/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:16 by epascual          #+#    #+#             */
/*   Updated: 2024/12/10 12:51:12 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstring(char const *s)
{
	int	res;

	res = 0;
	if (s == NULL)
	{
		res += printstring("(null)");
		return (res);
	}
	while (*s != 0)
	{
		res += printchar(*s);
		s++;
	}
	return (res);
}
//int main(){printstring("Comprovacion");printf("Comprovacion");}
