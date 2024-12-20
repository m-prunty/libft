/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputstrchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:45:44 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/18 18:18:46 by potz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_iputchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_iputstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_iputstr("(null)"));
	while (*str)
		count += ft_iputchar(*str++);
	return (count);
}
