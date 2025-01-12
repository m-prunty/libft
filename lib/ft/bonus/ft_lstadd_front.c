/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20../15 18:50:56 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/18 19:20:21 by potz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **alst, t_list *new_ele)
{
	if (alst)
	{
		if (*alst)
			new_ele->next = *alst;
		*alst = new_ele;
	}
}
