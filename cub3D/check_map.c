/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/10 17:33:14 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_from_start(t_map *map, int z)
{
	int	first;

	first = 0;
	while (map->map_cpy[z][first] != '1' && map->map_cpy[z][first])
	{
		if (map->map_cpy[z][first] == '0')
			exit_error(map, "map not closed");
		if (map->map_cpy[z][first] == 'N' || map->map_cpy[z][first] == 'S'
			|| map->map_cpy[z][first] == 'W' || map->map_cpy[z][first] == 'E')
			exit_error(map, "map error");
		first++;
	}
	if (map->map_cpy[z][first] != '1')
		exit_error(map, "problemo");
	return (first);
}

int	check_from_end(t_map *map, int z)
{
	int	last;

	last = ft_strlen(map->map_cpy[z]);
	while (map->map_cpy[z][last] != '1' && last >= 0)
	{
		if (map->map_cpy[z][last] == '0')
			exit_error(map, "map error");
		if (map->map_cpy[z][last] == 'N' || map->map_cpy[z][last] == 'S'
			|| map->map_cpy[z][last] == 'W' || map->map_cpy[z][last] == 'E')
			exit_error(map, "map error");
		last--;
	}
	if (map->map_cpy[z][last] != '1')
		exit_error(map, "problemo");
	return (last);
}

static void	check_the_line(t_map *map, int z)
{
	int	first;
	int last;
	int	tmp;
	
	first = check_from_start(map, z);
	last = check_from_end(map, z);
	tmp = first;
	while (tmp < last)
	{
		if (map->map_cpy[z][tmp] == '0' && (map->map_cpy[z + 1][tmp] == ' '
			|| map->map_cpy[z - 1][tmp] == ' ' || map->map_cpy[z][tmp + 1] == ' '
			|| map->map_cpy[z - 1][tmp - 1] == ' '))
			exit_error(map, "map error");
		tmp++;
	} 
	check_connect_start(map, z, first);
	check_connect_end(map, z, last);
}

static void	check_left_n_right(t_map *map)
{
	int	z;

	z = 1;
	while (map->map_cpy[z + 1])
	{	
		check_the_line(map, z);
		z++;
	}
}

static void	check_from_top(t_map *map)
{
	int	*check;
	int	z;
	int	y;

	y = 0;
	z = 0;
	check = init_tab(max_line_len(map->map_cpy));
	while (map->map_cpy[z] && check_tab(check, max_line_len(map->map_cpy)) != 1)
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == '1' && check[y] == 0)
				check[y] = 1;
			if (map->map_cpy[z][y] == '0' && check[y] != 1)
			{	
				free (check);
				exit_error(map, "map error");
			}
			y++;
		}
		y = 0;
		z++;
	}
	free (check);
}

static void	check_from_bot(t_map *map)
{
	int	*check;
	int	z;
	int	y;

	y = 0;
	z = tab_count(map->map_cpy) - 1;
	check = init_tab(max_line_len(map->map_cpy));
	while (z > 0 && check_tab(check, max_line_len(map->map_cpy)) != 1)
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == '1' && check[y] == 0)
				check[y] = 1;
			if ((map->map_cpy[z][y] == '0' && check[y] != 1)
					|| char_check(map->map_cpy[z][y]) != 1)
			{	
				free (check);
				exit_error(map, "map error");
			}
			y++;
		}
		y = 0;
		z--;
	}
	free (check);
}

void	basic_check(t_map *map)
{
	int	player;
	int	z;
	int	y;

	player = 0;
	z = 0;
	y = 0;
	if (tab_count(map->map_cpy) <= 2)
		exit_error(map, "map problem");
	while (map->map_cpy[z])
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == 'N' || map->map_cpy[z][y] == 'W'
				|| map->map_cpy[z][y] == 'E' || map->map_cpy[z][y] == 'S')
				player++;
			if (char_check(map->map_cpy[z][y]) != 1)
				exit_error(map, "unauthorized character");
			y++;
		}
		y = 0;
		z++;
	}
	if (player != 1)
		exit_error(map, "one player por favor");
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	map->line = 1;
	while (map->map_cpy[i])
	{
		map->line++;
		i++;
	}
	basic_check(map);
	check_from_top(map);
	check_from_bot(map);
	check_left_n_right(map);
}