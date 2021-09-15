/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:06:06 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:10:55 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_malloc_s(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_write_eachstr(const char *s, char c, char **tab)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = ft_substr(s, 0, i);
	if (dest == NULL)
		ft_free_split(tab);
	return (dest);
}

static char	**malloc_in_tab(char const *s1, char c)
{
	char	**tab;

	tab = malloc((ft_malloc_s(s1, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *s1, char c)
{
	int		i;
	int		j;
	int		counter;
	char	**tab;

	i = 0;
	j = 0;
	counter = 0;
	if (s1 == NULL)
		return (NULL);
	tab = malloc_in_tab(s1, c);
	while (s1[i])
	{
		while (s1[i] == c)
			i++;
		if (s1[i] && s1[i] != c)
		{
			tab[j++] = ft_write_eachstr(&s1[i], c, tab);
			while (s1[i] && s1[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
