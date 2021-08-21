/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:06:17 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/12 15:07:37 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	if (!(s))
		return (NULL);
	while (--i)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
