/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:27:51 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/23 13:27:58 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	only_snd_cmd(char **argv, char **envp, t_data *data)
{
	prep_argz_2(data, argv, envp);
	infile_prep(argv[1], data);
	exec_only_one(data, envp);
	free_for_all(data);
	exit (0);
}

void	error_check(int argc, char **argv, t_data *data, char **envp)
{
	if (argc != 5)
		quick_kill("check the arguments");
	data->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (data->outfile == -1)
		quick_kill("outfile not opened");
	if (argv[2][0] == '\0' && argv[3][0] != '\0')
	{
		ft_putstr_fd("zsh: permission denied:\n", 1);
		only_snd_cmd(argv, envp, data);
	}
	if (pipe(data->fd) == -1)
		quick_kill("pipe problem");
}

int	prep_argz_1(t_data *data, char **argv, char **envp)
{
	data->argz_1 = ft_split(argv[2], ' ');
	data->path_1 = path_finder(data, envp, 1);
	if (!data->path_1)
	{	
		ft_putstr_fd("zsh: command not found: ", 1);
		ft_putstr_fd(data->argz_1[0], 1);
		ft_putstr_fd("\n", 1);
		free_loop(data->argz_1);
		data->argz_1 = NULL;
	}
	return (1);
}

void	prep_argz_2(t_data *data, char **argv, char **envp)
{
	data->argz_2 = ft_split(argv[3], ' ');
	data->path_2 = path_finder(data, envp, 2);
	if (!data->path_2)
	{
		ft_putstr_fd("zsh: command not found: ", 1);
		ft_putstr_fd(data->argz_2[0], 1);
		free_for_all(data);
		exit (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	initialize_default_values(&data);
	error_check(argc, argv, &data, envp);
	prep_argz_1(&data, argv, envp);
	prep_argz_2(&data, argv, envp);
	infile_prep(argv[1], &data);
	exec(&data, envp);
	free_for_all(&data);
}
