/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 04:16:42 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/20 14:22:16 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief niave recursive function to check if a string is a number only 
 * determines if every element of str is a digit
 *
 * @param str string to check
 * @return 1 if isnum else 0
 */
int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	if (*str == '\0' && *(str - 1))
		return (1);
	if (ft_isdigit(*str))
		return (ft_isnum(++str) * 1);
	return (0);
}

/**
 * @brief checks if a string value is an integer
 * follows atoi rules; allows any n leading whitespace, one sign
 * calls ft_isnum to check the rest
 *
 * @param str string to check
 * @return +1/-1 if isnum else 0
 */
int	ft_isnumi(char *str)
{
	int	neg;

	if (!str)
		return (0);
	neg = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str ++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			neg *= -1;
		str++;
	}
	return (ft_isnum(str) * neg);
}

/**
 * @brief function to check if a string value is a float
 * calls ft_isnumi to check the integer part
 * calls ft_isnum to check the rest
 * times the the two results
 *
 * @param str string to check
 * @param dec set to 1 to prime boolean switch to deal with a single decimal
 * @return +1/-1 if isnum else 0
 */
int	ft_isnumf(char *str)
{
	char	*intg;
	char	*frac;

	if (!str)
		return (0);
	frac = ft_strchr(str, '.');
	if (!frac)
		return (ft_isnumi(str));
	intg = ft_substr(str, 0, (int)(str - frac));
	return (ft_isnumi(intg) * ft_isnum(frac + 1));
}

/**
 * @brief main function to test the isnumi and isnumf functions
 *
 * @return int
int main()
{
char *str1 = "123.456";
	char *str2 = "123";
	ft_printf("isnumi: %i\n", ft_isnumi(str2));
	ft_printf("isnumf: %i\n", ft_isnumf(str1, 1));
	ft_printf("isnumi: %i\n", ft_isnumi(""));
	ft_printf("isnumf: %i\n", ft_isnumf("0.0", 1));
	ft_printf("isnumf: %i\n", ft_isnumf(".0", 1));
	ft_printf("isnumf: %i\n", ft_isnumf("0.", 1));
	return (0);
}
 */
