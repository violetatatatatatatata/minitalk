/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:03 by epascual          #+#    #+#             */
/*   Updated: 2025/02/12 15:49:13 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	printpointcontfd(int fd, unsigned long long n, char *base)
{
	unsigned long long	num;
	int					res;

	res = 0;
	num = (unsigned long long)n;
	if (num > 16)
	{
		res += printpointcontfd(fd, (num / 16), base);
		res += printpointcontfd(fd, num % 16, base);
	}
	else if (num == 16)
	{
		res += printstringfd(fd, "10");
	}
	else
	{
		printcharfd(fd, base[num]);
		res++;
	}
	return (res);
}

int	printpointfd(int fd, unsigned long long n, char *base)
{
	int	res;

	res = 0;
	if (n == 0)
	{
		res += printstringfd(fd, "(nil)");
		return (res);
	}
	res += printstringfd(fd, "0x");
	res += printpointcontfd(fd, n, base);
	return (res);
}
