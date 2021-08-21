/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:35:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 13:55:35 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
