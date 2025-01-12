/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:42:19 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/12 03:50:57 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/**
 * @brief
 * Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * External functs. malloc
 *
 * @param	s: The string from which to create the substring. 
 * @param	start: The start index of the substring in the string ’s’.
 * @param	len: The maximum length of the substring.
 * @return  The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	int		i;
	int		slen;

	slen = (int)ft_strlen(s);
	if ((int)start + (int)len > slen)
		len = slen - start;
	if ((int)start > slen || len <= 0)
		return (ft_strdup(""));
	i = 0;
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub || !len)
	{
		return (NULL);
	}
	while (i < (int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}

/*
char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	int		i;
	int		slen;

	slen = (int)ft_strlen(s);
	i = 0;
	if ((int)start + (int)len > slen)
		len = slen - start;
	if ((int)start > slen || len <= 0 )
		return (ft_strdup(""));
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return NULL;
	while (i < (int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}

*/
/*
int main()
{
	char * s = "fgdfghhg";

	printf("%s",ft_substr(s, 2,2));
	return 0;
}
*/
