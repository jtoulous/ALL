/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:28:27 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/23 13:29:35 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	infile_prep(char *argv, t_data *data)
{
	int	fd;

	if (access(argv, F_OK) != 0)
	{
		free_for_all(data);
		ft_putstr_fd("zsh: no such file or directory: ", 1);
		ft_putstr_fd(argv, 1);
		exit (0);
	}	
	fd = open(argv, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close (fd);
}

void	free_for_all(t_data *data)
{
	if (data->argz_1)
		free_loop(data->argz_1);
	if (data->argz_2)
		free_loop(data->argz_2);
	if (data->path_1)
		free (data->path_1);
	if (data->path_2)
		free (data->path_2);
	mega_close(data->outfile, data->fd[0], data->fd[1], -1);
}

void	exec(t_data *data, char **envp)
{
	int	pid;

	if (data->argz_1 != NULL)
	{	
		pid = fork();
		if (pid == 0)
		{
			dup2(data->fd[1], STDOUT_FILENO);
			mega_close(data->fd[0], data->fd[1], data->outfile, -1);
			execve(data->path_1, data->argz_1, envp);
		}
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(data->outfile, STDOUT_FILENO);
		dup2(data->fd[0], STDIN_FILENO);
		mega_close(data->fd[0], data->fd[1], data->outfile, -1);
		execve(data->path_2, data->argz_2, envp);
	}
}

void	exec_only_one(t_data *data, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(data->outfile, STDOUT_FILENO);
		mega_close(data->fd[0], data->fd[1], data->outfile, -1);
		execve(data->path_2, data->argz_2, envp);
	}
}

int	path_index(char **envp)
{
	int	z;

	z = 0;
	while (envp[z][0] != 'P' || envp[z][1] != 'A'
		|| envp[z][2] != 'T' || envp[z][3] != 'H')
		z++;
	return (z);
}
