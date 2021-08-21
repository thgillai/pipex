/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:26:18 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 15:41:29 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *reste)
{
	int		i;
	char	*line;

	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
	{
		line[i] = reste[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_strjoinplus(char *reste, char *buff, int ret)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc((ft_strlen2(reste) + ret + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (reste && reste[i])
	{
		new[i] = reste[i];
		i++;
	}
	j = 0;
	while (j < ret)
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	if (reste)
		free(reste);
	return (new);
}

static char	*free_reste(char *reste, int *ret, int j)
{
	char	*new;
	int		i;

	*ret = 0;
	i = is_line(reste);
	if (i < 0)
	{
		if (i == -1)
			free(reste);
		return (0);
	}
	new = (char *)malloc((ft_strlen2(reste) - i + 1) * sizeof(char));
	if (!new)
	{
		*ret = -1;
		free(reste);
		return (0);
	}
	i++;
	norme_gnl(reste, i, &j, new);
	new[j] = '\0';
	free(reste);
	return (new);
}

static int	get_next_l(int fd, char **line, unsigned int size)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*reste[FOPEN_MAX];
	int			ret;

	if (read(fd, buff, 0) < 0)
		return (-1);
	*line = NULL;
	ret = 1;
	while (is_line(reste[fd]) < 0 && ret)
	{
		ret = read(fd, buff, size);
		reste[fd] = ft_strjoinplus(reste[fd], buff, ret);
		if (!reste[fd])
			return (-1);
	}
	*line = get_line(reste[fd]);
	if (!*line)
		return (-1);
	reste[fd] = free_reste(reste[fd], &ret, 0);
	if (!reste[fd])
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	unsigned int	size;

	if (BUFFER_SIZE <= 0 || !line || fd > FOPEN_MAX)
		return (-1);
	size = BUFFER_SIZE;
	size += 1;
	return (get_next_l(fd, line, size));
}
