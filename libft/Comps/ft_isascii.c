/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:50:26 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:33:47 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_isascii(int c)
{
	if ((sizeof(c) == sizeof(unsigned char)) || (c >= 0 && c <= 127))
	{
		return (1);
	}
	return (0);
}
