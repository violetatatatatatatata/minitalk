/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:00 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:11:51 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strdup(const char *s)
{
	char				*fin;
	unsigned long		tam;
	int					i;

	i = 0;
	tam = ft_strlen((char *)s);
	fin = (char *)malloc(sizeof(char) * tam + 1);
	if (!fin)
		return (NULL);
	while (s[i])
	{
		fin[i] = s[i];
		i++;
	}
	fin[i] = 0;
	return (fin);
}
