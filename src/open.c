/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:05:30 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/17 09:22:52 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_w(char *av)
{
	int	fd;

	fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit_error("Outfile Error: fail to open and write\n");
	return (fd);
}

int	open_r(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_error("Infile Error: fail to open and read\n");
	return (fd);
}
