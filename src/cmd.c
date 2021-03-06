/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:49:33 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/17 09:22:45 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	cmd_1(t_pipe *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd1, ' ');
	if (cmd == NULL)
		exit_error("Split Error: split failed in cmd_1\n");
	binary = pathing(pipex, cmd[0]);
	pipex->pid_1 = fork();
	if (pipex->pid_1 == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		execve(binary, cmd, pipex->envp);
		exit_error("Cmd_1 Error: execve failed\n");
	}
	waitpid(pipex->pid_1, NULL, 0);
	close(pipex->infile);
	close(pipex->fd[1]);
	pipex->fd[1] = -1;
	ft_free_split(cmd);
	free(binary);
	return (0);
}

int	cmd_2(t_pipe *pipex)
{
	char	**cmd;
	char	*binary;

	cmd = ft_split(pipex->cmd2, ' ');
	if (cmd == NULL)
		exit_error("Split Error: split failed in cmd_2\n");
	binary = pathing(pipex, cmd[0]);
	pipex->pid_2 = fork();
	if (pipex->pid_2 == 0)
	{
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		execve(binary, cmd, pipex->envp);
		exit_error("Cmd_2 Error: execve failed\n");
	}
	waitpid(pipex->pid_2, NULL, 0);
	close(pipex->outfile);
	close(pipex->fd[0]);
	pipex->fd[0] = -1;
	ft_free_split(cmd);
	free(binary);
	return (0);
}
