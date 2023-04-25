/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:30:10 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/23 13:30:50 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_lst(char **envp)
{
	int		idx;
	int		z;
	int		y;
	char	*paths;
	char	**fnl;

	z = 5;
	y = 0;
	idx = path_index(envp);
	while (envp[idx][z])
		z++;
	paths = ft_calloc(z, sizeof(char));
	if (!paths)
		return (NULL);
	z = 5;
	while (envp[idx][z])
	{
		paths[y] = envp[idx][z];
		y++;
		z++;
	}
	fnl = ft_split(paths, ':');
	free (paths);
	return (fnl);
}

char	*path_finder(t_data *data, char **envp, int opt)
{
	char	**paths;
	char	*cmd;
	char	*path_to_test;
	int		z;

	z = 0;
	if (opt == 1)
		cmd = data->argz_1[0];
	if (opt == 2)
		cmd = data->argz_2[0];
	paths = path_lst(envp);
	while (paths[z])
	{
		path_to_test = triple_strjoin(paths[z], "/", cmd);
		if (access(path_to_test, F_OK) == 0)
		{	
			free_loop(paths);
			return (path_to_test);
		}
		free (path_to_test);
		z++;
	}
	free_loop(paths);
	return (NULL);
}

void	initialize_default_values(t_data *data)
{
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->outfile = -1;
}
