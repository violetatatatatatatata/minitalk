/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:29:28 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:13:45 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] && (count < (size -1)))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}
