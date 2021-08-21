/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:51:33 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 13:48:42 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*back;

	back = *alst;
	if (*alst)
	{
		while (back->next != NULL)
			back = back->next;
		back->next = new;
	}
	else
		*alst = new;
}
