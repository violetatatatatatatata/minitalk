/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:40:36 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:35:25 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = -num;
		}
		if (num >= 10)
		{
			ft_putnbr_fd(num / 10, fd);
		}
		ft_putchar_fd(((num % 10) + '0'), fd);
	}
}
