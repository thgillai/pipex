/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:49:12 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 13:52:09 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	if (src < dest)
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
