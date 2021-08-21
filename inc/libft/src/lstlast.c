/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:37:57 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 12:55:09 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
