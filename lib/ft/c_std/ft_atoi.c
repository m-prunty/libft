/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:55:27 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/13 08:56:03 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	neg;

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
		res = (res * 10 + (*nptr - 48));
		nptr++;
	}
	return (res * neg);
}
