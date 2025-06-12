/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:22:12 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:05:40 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
