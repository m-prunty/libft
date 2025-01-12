/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <mprunty@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:20:04 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/12 20:02:40 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	val(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	else
		return ((int)c - 'A' + 10);
}

int	ft_atoi_base(const char *nptr, int base)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	while (ft_isspace(*nptr))
		nptr ++;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			neg *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = (res * base) + (val(*nptr));
		nptr++;
	}
	return (res * neg);
}
/*/
 int main () {
 char *s;
 char *s2;

 s = "-1000000000000000000000";
 s2 = "-111";
 printf("%i\n", ft_atoi_base(s, 2));
 printf("%i", ft_atoi_base(s2, 2));

/*/
