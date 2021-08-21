/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:02:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/08/21 15:08:46 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Exit et close les fichiers de la structure si il y en a

char	*exit_error_2(t_pipe *pipex, char *s)
{
	ft_putstr_fd(s, 0);
	if (pipex->infile > 0)
		close(pipex->infile);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	if (pipex->fd[0] > 0)
		close(pipex->fd[0]);
	if (pipex->fd[1] > 0)
		close(pipex->fd[1]);
	exit(EXIT_FAILURE);
}

// Trouve le path du repertoire courant dans envp

static char	*path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
		}
		i++;
	}
	exit_error("Envp error: PATH environement undefined");
	return (NULL);
}

// Remplis la structure

static t_pipe	fill_str(char **av, char **envp)
{
	t_pipe		pipex;

	ft_memset(&pipex, 0, sizeof(pipex));
	pipex.infile = open_r(av[1]);
	pipex.outfile = open_w(av[4]);
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	pipex.path = path(envp);
	if (pipex.path == NULL)
		exit_error("Path error: no path");
	pipex.envp = envp;
	return (pipex);
}

// main

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac != 5)
		exit_error("ArgNum error: ./pipex infile cmd1 cmd2 outfile");
	pipex = fill_str(av, envp);
	if (pipe(pipex.fd) == -1)
		exit_error("Pipe creation failed");
	cmd_1(&pipex);
	cmd_2(&pipex);
	free(pipex.path);
}
