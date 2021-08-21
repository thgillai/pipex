/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:52:36 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/17 14:52:44 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;
	const unsigned char		*s1_b;
	const unsigned char		*s2_b;

	i = 0;
	s1_b = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	while (s1_b[i] && s2_b[i])
	{
		if (s1_b[i] != s2_b[i])
			return (s1_b[i] - s2_b[i]);
		i++;
	}
	if (s1_b[i] != s2_b[i])
		return (s1_b[i] - s2_b[i]);
	return (0);
}
