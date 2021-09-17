/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:11:20 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/17 09:23:12 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*parse_entire_path(char *cmd_0, char *directory)
{
	char	*path;
	char	*entire_path;

	if (directory[ft_strlen(directory) - 1] == '/')
		path = ft_strdup(directory);
	else
		path = ft_strjoin(directory, "/");
	if (path == NULL)
		exit_error("Entire path Error: Cant get entire directory path\n");
	entire_path = ft_strjoin(path, cmd_0);
	if (entire_path == NULL)
		exit_error("Entire path Error: path is empty\n");
	free(path);
	return (entire_path);
}

static char	*parse_path(t_pipe *pipex, char *cmd_0)
{
	size_t	index;
	char	**directories;
	char	*path;

	index = 0;
	directories = ft_split(pipex->path, ':');
	if (directories == NULL)
		exit_error("Split Error: Can't get directories\n");
	while (directories[index])
	{
		path = parse_entire_path(cmd_0, directories[index]);
		pipex->directory_fd = open(path, O_RDONLY);
		if (pipex->directory_fd == -1)
			free(path);
		else
		{
			ft_free_split(directories);
			close(pipex->directory_fd);
			return (path);
		}
		index++;
	}
	ft_free_split(directories);
	return (exit_error_2(pipex, "Path Error: Wrong/Inexistant path\n"));
}

char	*pathing(t_pipe *pipex, char *cmd_0)
{
	char	*path;

	if (cmd_0[0] == '/' || cmd_0[0] == '.' || cmd_0[0] == '~')
	{
		path = ft_strdup(cmd_0);
		if (path == NULL)
			exit_error("Pathing Error : Path is NULL\n");
		return (path);
	}
	return (parse_path(pipex, cmd_0));
}
