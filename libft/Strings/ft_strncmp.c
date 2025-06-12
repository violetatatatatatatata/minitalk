/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:39:31 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 19:14:01 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	iter;
	int				res;

	iter = 0;
	res = 0;
	while ((iter < n) && (s1[iter] || s2[iter]))
	{
		if (s1[iter] != s2[iter])
		{
			res = (unsigned char)(s1[iter]) - (unsigned char)(s2[iter]);
			return (res);
		}
		iter++;
	}
	return (res);
}
