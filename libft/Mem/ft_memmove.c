/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:33:36 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:39:25 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sr;

	dest = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (dest > sr)
	{
		while (len--)
			dest[len] = sr[len];
	}
	else if (dest < sr)
		ft_memcpy(dst, src, len);
	return (dst);
}*/

void	*ft_memmove(void *dest, const void *src, size_t c)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src)
		ft_memcpy(dest, src, c);
	else
	{
		while (c--)
			d[c] = s[c];
	}
	return (dest);
}
