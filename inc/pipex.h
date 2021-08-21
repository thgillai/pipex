/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:02:32 by thgillai          #+#    #+#             */
/*   Updated: 2021/08/05 15:34:03 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/inc/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		directory_fd;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**envp;
	pid_t	pid_1;
	pid_t	pid_2;
}			t_pipe;

/* Open */
int	open_w(char *av);
int	open_r(char *av);

/* Cmd */
int	cmd_1(t_pipe *pipex);
int	cmd_2(t_pipe *pipex);

/* Path */
char	*pathing(t_pipe *pipex, char *cmd_0);

/* Utils */
char	*exit_error_2(t_pipe *pipex, char *s);

#endif
