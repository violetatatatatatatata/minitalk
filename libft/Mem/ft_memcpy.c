/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:33:21 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:39:08 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t c)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < c)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
