/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:38:09 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:11:36 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	p;
	size_t	i;

	p = 1;
	i = 0;
	while (*s)
	{
		if (*s == c)
			p++;
		s++;
	}
	r = (char **)malloc(sizeof(char *) * p);
	if (!r)
		return (NULL);
	while (i < p)
	{
		while (*s != c)
		{
			*r[i] = *s;
			s++;
			r[i]++;
		}
		*r[i] = 0;
		i++;
	}
	r[i] = NULL;
	return (r);
}*/

static int	count(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
