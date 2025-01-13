/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:44:16 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/13 09:00:13 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <errno.h>

int	init_parse(char *nptr, int *base, char **endptr, int *neg)
{
	int	i;

	i = 0;
	if (*base < 0 || *base == 1 || *base > 36)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		*neg = (nptr[i++] == '-');
	return (i);
}

int	chk_base(const char *nptr, int base)
{
	if (base == 0)
	{
		if (nptr[0] == '0')
		{
			if (nptr[1] == 'x' || nptr[1] == 'X')
				return (16);
			return (8);
		}
		return (10);
	}
	return (base);
}

int	get_char(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

long	handle_overflow(long long res, int neg, char **endptr, const char *nptr)
{
	if (res > LONG_MAX || res < LONG_MIN)
	{
		errno = ERANGE;
		if (neg)
			res = LONG_MIN;
		else
			res = LONG_MAX;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return ((long)res);
}

/**
 * !!!!
 * WARNING: NOT HANDLING OVERFLOW YET
 * !!!!
 * @brief        The strtol() function converts the initial part of the string in
 nptr to a long integer value according to the given base, which
 must be between 2 and 36 inclusive, or be the special value 0.

 The string may begin with an arbitrary amount of white space (as
 determined by isspace(3)) followed by a single optional '+' or
 '-' sign.  If base is zero or 16, the string may then include a
 "0x" or "0X" prefix, and the number will be read in base 16;
 otherwise, a zero base is taken as 10 (decimal) unless the next
 character is '0', in which case it is taken as 8 (octal).

 The remainder of the string is converted to a long value in the
 obvious manner, stopping at the first character which is not a
 valid digit in the given base.  (In bases above 10, the letter
 'A' in either uppercase or lowercase represents 10, 'B'
 represents 11, and so forth, with 'Z' representing 35.)

 If endptr is not NULL, and the base is supported, strtol() stores
 the address of the first invalid character in *endptr.  If there
 were no digits at all, strtol() stores the original value of nptr
 in *endptr (and returns 0).  In particular, if *nptr is not '\0'
 but **endptr is '\0' on return, the entire string is valid.

 The strtoll() function works just like the strtol() function but
 returns a long long integer value.
 *
 * @param nptr 
 * @param endptr 
 * @param base 
 */
long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base)
{
	long long	res;
	int			neg;
	long long	overflow;

	res = 0;
	neg = 0;
	overflow = LONG_MAX;
	nptr = nptr + init_parse((char *)nptr, &base, endptr, &neg);
	base = chk_base((char *)nptr, base);
	if ((base == 0 || base == 16) && nptr[0] == '0'
		&& (nptr[1] == 'x' || nptr[1] == 'X'))
		nptr += 2;
	while (get_char(*nptr) >= 0 && get_char(*nptr) < base && res <= overflow)
		res = res * base + get_char(*nptr++);
	if (neg)
		res = -res;
	return (handle_overflow(res, neg, endptr, nptr));
}

/*
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

void test_strtol(const char *nptr, int base) {
	char *end_std, *end_ft;
	errno = 0;
	long std_result = strtol(nptr, &end_std, base);
	int std_errno = errno;

	errno = 0;
	long ft_result = ft_strtol(nptr, &end_ft, base);
	int ft_errno = errno;

	// Print results
	printf("Input: \"%s\", Base: %d\n", nptr, base);
	printf("  strtol: Result = %ld, Endptr = \"%s\", Errno = %d\n",
	std_result, end_std, std_errno);
	printf("  ft_strtol: Result = %ld, Endptr = \"%s\", Errno = %d\n",
	ft_result, end_ft, ft_errno);

	// Compare results
	if (std_result != ft_result || std_errno != ft_errno || end_std != end_ft) {
		printf("  \x1B[31m[Mismatch detected!]\n\x1B[0m" );
	} else {
		printf("  \x1B[32m[Match]\n\x1B[0m" );
	}
	printf("----------------------------------------\n");
}

int main() {
	// Test cases
	const char *test_cases[] = {
		"12345", "+12345", "-12345", // Base 10
		"0x1A3F", "-0XFF", "FF",    // Base 16
		"0755", "-0755",            // Base 8
		"1101", "-1101",            // Base 2
		"z", "10",                  // Base 36
		"0x1F", "-0x10", "075",     // Base 0 (auto-detect)
		"123abc", "0x123G", "abc",  // Invalid characters
		"",                         // Empty string
		"   12345", "\t\n\v\f\r123", // Leading whitespace
		"9223372036854775808", "-9223372036854775809", // Overflow/Underflow
		"10102",                    // Base 2 with invalid characters
		"ZZZZ",                     // Base 36
		"123",                      // Base 1 (invalid)
		NULL                        // End of test cases
	};

	int bases[] = {10, 16, 8, 2, 36, 0}; // Test with these bases
	size_t num_bases = sizeof(bases) / sizeof(bases[0]);

	for (size_t i = 0; test_cases[i] != NULL; i++) {
		for (size_t j = 0; j < num_bases; j++) {
			test_strtol(test_cases[i], bases[j]);
		}
	}

	return 0;
}
*/
