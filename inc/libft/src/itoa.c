/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:03:13 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 14:30:23 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	calc_size(long nb)
{
	int	size;

	size = 1;
	if (nb < 0)
		size++;
	while (nb / 10)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

void	norme_itoa(int i, int nb, int div, char *str)
{
	while (div)
	{
		str[i++] = nb / div + '0';
		nb = nb % div;
		div = div / 10;
	}
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	long	div;
	long	nb;

	nb = (long)nbr;
	str = (char *)malloc(calc_size(nb) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	div = 1;
	while (nb / div > 9)
		div *= 10;
	norme_itoa(i, nb, div, str);
	str[i] = '\0';
	return (str);
}
