/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:09:27 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 13:57:20 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	const unsigned char		*s1_b;
	const unsigned char		*s2_b;

	i = 0;
	s1_b = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	while (s1_b[i] && s2_b[i] && i < n)
	{
		if (s1_b[i] != s2_b[i])
			return (s1_b[i] - s2_b[i]);
		i++;
	}
	if (s1_b[i] != s2_b[i] && i != n)
		return (s1_b[i] - s2_b[i]);
	return (0);
}
