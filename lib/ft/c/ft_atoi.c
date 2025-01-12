/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:55:27 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/12 19:58:25 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isblank(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
	while (ft_isblank(*nptr))
		nptr ++;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			neg *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10 + (*nptr - 48);
		nptr++;
	}
	return (res * neg);
}
