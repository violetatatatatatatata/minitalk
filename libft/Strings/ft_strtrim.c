/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:37:56 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:12:15 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*tp;
	size_t	i;
	size_t	f;

	if (!s1 || !set)
		return (NULL);
	tp = (char *)s1;
	f = ft_strlen(tp);
	i = 0;
	while (i < f && ft_strchr(set, tp[i]) != 0)
		i++;
	while (i < f && ft_strrchr(set, tp[f]) != 0)
		f--;
	res = (char *)malloc(sizeof(char) * (f - i +1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, tp + i, f - i);
	return (res);
}*/

static int
	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
