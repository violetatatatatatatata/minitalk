/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:35:48 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:45:47 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_calloc(unsigned long nelem, unsigned long elsize)
{
	void	*ptr;

	if ((nelem * elsize) > 2147483647)
		return (NULL);
	ptr = (void *)malloc(nelem * elsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
