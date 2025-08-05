/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:23:26 by epascual          #+#    #+#             */
/*   Updated: 2024/12/10 15:41:14 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Implemento como musl porque openbsd y glibc no me gustan tanto
//Restrict significa que este puntero solo puede ser leido
//A diferencia del printf real de musl no paso el stdout como parametro
int	ft_printf(char const *p, ...)
{
	va_list	opc;
	int		ret;

	va_start(opc, p);
	ret = realprintf(p, opc);
	va_end(opc);
	return (ret);
}

void	checker(int *ret, char check, va_list opc)
{
	if (check == 'c')
		*ret += printchar(va_arg(opc, int));
	if (check == 's')
		*ret += printstring(va_arg(opc, char *));
	if (check == 'p')
		*ret += printpoint(va_arg(opc, unsigned long long), "0123456789abcdef");
	if (check == 'd')
		*ret += printnum(va_arg(opc, int), "0123456789");
	if (check == 'i')
		*ret += printnum(va_arg(opc, int), "0123456789");
	if (check == 'u')
		*ret += printunum(va_arg(opc, unsigned int), "0123456789");
	if (check == 'x')
		*ret += printunum(va_arg(opc, unsigned int), "0123456789abcdef");
	if (check == 'X')
		*ret += printunum(va_arg(opc, unsigned int), "0123456789ABCDEF");
	if (check == '%')
		*ret += printchar('%');
}

int	realprintf(char const *p, va_list opc)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (p[i])
	{
		if (p[i] != '%')
			ret += printchar(p[i]);
		else
		{
			i++;
			checker(&ret, p[i], opc);
		}
		i++;
	}
	return (ret);
}
//int main(){char *s="Probando";
//ft_printf("Prueba y %s", s);return (0);}
