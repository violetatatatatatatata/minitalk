/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:11 by epascual          #+#    #+#             */
/*   Updated: 2025/06/12 14:56:37 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char a)
{
	if (write(1, &a, 1) < 1)
		return (0);
	return (1);
}

int	strilen(char *s)
{
	unsigned int	ret;

	ret = 0;
	while (*s)
	{
		ret++;
		s++;
	}
	return (ret);
}

int	printnum(long n, char *base)
{
	int		b;
	long	num;
	int		res;

	res = 0;
	b = strilen(base);
	num = (long)n;
	if (num < 0)
	{
		printchar('-');
		num = -num;
		res++;
	}
	if (num >= b)
	{
		res += printnum(num / b, base);
		res += printnum(num % b, base);
	}
	else
	{
		printchar(base[num]);
		res++;
	}
	return (res);
}

int	printunum(unsigned int n, char *base)
{
	unsigned int	b;
	unsigned int	num;
	int				res;

	res = 0;
	b = strilen(base);
	num = (unsigned long)n;
	if (num >= b)
	{
		res += printunum(num / b, base);
		res += printunum(num % b, base);
	}
	else
	{
		printchar(base[num]);
		res++;
	}
	return (res);
}
//int main(){printnum(-123, "0123456789");printf("\n%d\n",-123);return(0);}
