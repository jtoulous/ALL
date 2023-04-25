/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:31:06 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/23 13:32:37 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct pipe_data
{
	int		outfile;
	char	**argz_1;
	char	**argz_2;
	char	*path_1;
	char	*path_2;
	int		fd[2];
}		t_data;

int		prep_argz_1(t_data *data, char **argv, char **envp);
void	prep_argz_2(t_data *data, char **argv, char **envp);
void	error_check(int argc, char **argv, t_data *data, char **envp);
void	only_snd_cmd(char **argv, char **envp, t_data *data);
void	infile_prep(char *argv, t_data *data);
void	free_for_all(t_data *data);
void	exec(t_data *data, char **envp);
char	**path_lst(char **envp);
char	*path_finder(t_data *data, char **envp, int opt);
int		path_index(char **envp);
void	initialize_default_values(t_data *data);
void	exec_only_one(t_data *data, char **envp);

#endif
