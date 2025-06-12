/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:15:11 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:34:57 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
static int	get_digit(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*ifzero(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = get_digit((long int)n);
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
		str = ifzero(n);
	if (n < 0)
	{
		str[0] = '-';
		n = (long int)(n * -1);
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = (long int)(n / 10);
	}
	return (str);
}*/

static	int	count_char(int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num = num *(-1);
			count++;
		}
		while (num != 0)
		{
			num = num / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	len = count_char(n);
	nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = ((nbr % 10) + '0');
		nbr /= 10;
		len--;
	}
	return (str);
}
