/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:03 by epascual          #+#    #+#             */
/*   Updated: 2024/12/10 16:20:20 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpointcont(unsigned long long n, char *base)
{
	unsigned long long	num;
	int					res;

	res = 0;
	num = (unsigned long long)n;
	if (num > 16)
	{
		res += printpointcont((num / 16), base);
		res += printpointcont(num % 16, base);
	}
	else if (num == 16)
	{
		res += printstring("10");
	}
	else
	{
		printchar(base[num]);
		res++;
	}
	return (res);
}

int	printpoint(unsigned long long n, char *base)
{
	int	res;

	res = 0;
	if (n == 0)
	{
		res += printstring("(nil)");
		return (res);
	}
	res += printstring("0x");
	res += printpointcont(n, base);
	return (res);
}
