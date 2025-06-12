/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:37:38 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:13:29 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*res;
	size_t	i;
	size_t	it;

	l = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(sizeof(char) * l);
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		res[i] = (char)(s1[i]);
		i++;
	}
	it = 0;
	while (it < ft_strlen((char *)s2))
	{
		res[i] = (char)(s2[it]);
		it++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
