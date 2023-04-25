/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:34:09 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:34:29 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func(int keycode, void *param)
{	
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		kill_func(param);
	if (keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Up || keycode == XK_Down)
		move(keycode, data);
	return (0);
}

int	kill_func(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free (data->mlx);
	exit(1);
	return (0);
}

int	mouse_func(int keycode, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 4)
		zoom(data, x, y, 1);
	if (keycode == 5)
		zoom(data, x, y, 2);
	return (0);
}
