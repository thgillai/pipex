/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:33:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 12:51:54 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (res > 2147483648)
	{
		if (neg == -1)
			return (0);
		return (-1);
	}
	return (res * neg);
}
