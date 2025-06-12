/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstalast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:47:42 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:36:09 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstalast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}
