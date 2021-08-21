/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:14:30 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 13:48:55 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	if (*lst == NULL || del == NULL)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		*lst = buffer;
		ft_lstdelone(*lst, del);
		buffer = buffer->next;
	}
	*lst = NULL;
}
