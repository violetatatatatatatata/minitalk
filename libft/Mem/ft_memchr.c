/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:35:03 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:38:47 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned long	iter;
	void			*ns;

	ns = (void *)s;
	iter = 0;
	while (iter < n)
	{
		if (((unsigned char *)ns)[iter] == (unsigned char)c)
		{
			return (ns + iter);
		}
		iter++;
	}
	return (NULL);
}
