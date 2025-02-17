/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20../15 18:53:23 by mprunty           #+#    #+#             */
/*   Updated: 2024/12/26 23:18:51 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_ele;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new_ele = ft_lstnew((*f)(lst->content));
		if (!(new_ele))
		{
			while (first)
			{
				new_ele = first->next;
				(*del)(first->content);
				free(first);
				first = new_ele;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new_ele);
		lst = lst->next;
	}
	return (first);
}
