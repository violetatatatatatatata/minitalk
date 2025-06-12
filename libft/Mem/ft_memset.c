/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:32:59 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:39:17 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	iter;

	iter = 0;
	while (iter < count)
	{
		((char *)dest)[iter] = (char)c;
		iter++;
	}
	return (dest);
}
