/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:40:12 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:35:17 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	while (*s != 0)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
