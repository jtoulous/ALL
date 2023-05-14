/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:53:34 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/10 17:32:40 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map_utils(t_map *map, char *gnl)
{
	int	i;

	map->map_cpy[0] = gnl;
	i = 1;
	while (i < map->line)
	{
		map->map_cpy[i] = get_next_line(map->fd);
		i++;
	}
	map->map_cpy[i] = NULL;
}	

void	copy_map(t_map *map, char **argv)
{
	int		j;
	char	*gnl;

	line_counter(map);
	map->map_cpy = ft_calloc((map->line + 1), sizeof(char *));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(map->fd);
	while (gnl != NULL && ft_strncmp(gnl, "1", 1) != 0)
	{
		j = 0;
		while (gnl[j] == ' ' || gnl[j] == '\t')
			j++;
		if ((ft_strncmp(&gnl[j], "1", 1) == 0
				|| ft_strncmp(&gnl[j], "0", 1) == 0)
			&& gnl[j] != '\0')
			break ;
		free (gnl);
		gnl = get_next_line(map->fd);
	}
	copy_map_utils(map, gnl);
	close(map->fd);
}	

void	open_and_copy(char **argv, t_map *map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(argv[1]) - 1;
	if (argv[1][len] != 'b'
		|| argv[1][len - 1] != 'u'
		|| argv[1][len - 2] != 'c'
		|| argv[1][len - 3] != '.')
	{
		printf("Please enter a valid map\n");
		printf("Example map.cub\n");
		free_map(map);
		exit (1);
	}
	map->line = 1;
	map->fd = open(argv[1], O_RDONLY);
	copy_map(map, argv);
	check_map(map);
}

void	connect_start_above(t_map *map, int line, int start, int start_above)
{
	if (start > start_above)
	{
		while (start_above < start - 1)
		{
			if (map->map_cpy[line - 1][start_above] == '0')
				exit_error(map, "map error");
			start_above++;
		}
	}
	else
	{
		while (start < start_above - 1)
		{
			if (map->map_cpy[line][start] == '0')
				exit_error(map, "map error");
			start++;
		}
	}
}

void	connect_start_under(t_map *map, int line, int start, int start_under)
{
	if (start_under < start)
	{
		while (start_under < start - 1)
		{
			if (map->map_cpy[line + 1][start_under] == '0')
				exit_error(map, "map error");
			start_under++;
		}
	}
	else
	{
		while (start < start_under - 1)
		{
			if (map->map_cpy[line][start] == '0')
				exit_error(map, "map error");
			start++;
		}
	}
}

void	check_connect_start(t_map *map, int line, int start)
{
	int start_above;
	int	start_under;

	start_above = check_from_start(map, line - 1);
	start_under = check_from_start(map, line + 1);
	connect_start_above(map, line, start, start_above);
	connect_start_under(map, line, start, start_under);
}

void	connect_end_above(t_map *map, int line, int last, int last_above)
{
	if (last_above > last)
	{
		while (last_above > last + 1)
		{
			if (map->map_cpy[line - 1][last_above] == '0')
				exit_error(map, "map error");
			last_above--;
		}
	}
	else
	{
		while (last > last_above + 1)
		{
			if (map->map_cpy[line][last] == '0')
				exit_error(map, "map error");
			last--;
		}
	}
}

void	connect_end_under(t_map *map, int line, int last, int last_under)
{
	if (last_under > last)
	{
		while (last_under > last + 1)
		{
			if (map->map_cpy[line + 1][last_under] == '0')
				exit_error(map, "map error");
			last_under--;
		}
	}
	else
	{
		while (last > last_under + 1)
		{
			if (map->map_cpy[line][last] == '0')
				exit_error(map, "map error");
			last--;
		}
	}
}

void	check_connect_end(t_map *map, int line, int last)
{
	int last_above;
	int	last_under;

	last_above = check_from_end(map, line - 1);
	last_under = check_from_end(map, line + 1);
	connect_end_above(map, line, last, last_above);
	connect_end_under(map, line, last, last_under);
}