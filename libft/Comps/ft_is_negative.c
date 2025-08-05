/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:05:19 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:34:27 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
void	ft_is_negative(int num)
{
	char	p;
	char	n;

	p = 'P';
	n = 'N';
	if (num >= 0)
	{
		write(1, &p, 1);
	}
	else
	{
		write(1, &n, 1);
	}
}
*/
int	ft_is_negative(long num)
{
	if (num < 0)
		return (1);
	return (0);
}
//int main(void){ft_is_negative(-12);return(0);}
