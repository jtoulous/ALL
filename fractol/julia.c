/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:34:43 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:36:21 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init_1(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_putstr_fd("failed to create display\n", 1);
		exit (0);
	}
	data->win = mlx_new_window(data->mlx, win_size('x', 2),
			win_size('y', 2), "fnetre");
	data->zoom = 300;
	data->x1 = -1;
	data->x2 = 1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->max_iter = 150;
	data->img_x = (data->x2 - data->x1) * data->zoom;
	data->img_y = (data->y2 - data->y1) * data->zoom;
}

void	julia_init_2(t_data *data, int x, int y)
{
	data->c_r = data->jul_cr;
	data->c_i = data->jul_ci;
	data->z_r = x / data->zoom + data->x1;
	data->z_i = y / data->zoom + data->y1;
}

void	draw_julia(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->img_x)
	{
		y = 0;
		while (y < data->img_y)
		{
			julia_init_2(data, x, y);
			julia_calc(data, x, y);
			y++;
		}
		x++;
	}
}

void	julia_calc(t_data *data, int x, int y)
{
	double		tmp;
	int			i;

	i = 0;
	while (i < data->max_iter && value_check(data) == 1)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * tmp + data->c_i;
		i++;
	}
	if (i >= data->max_iter)
		img_pxl_put(data, x, y, 0X00000000);
	else
		img_pxl_put(data, x, y, 0x00220000 * i);
}

void	julia(double c_r, double c_i)
{
	t_data	data;

	data.fract_type = 2;
	data.jul_cr = c_r;
	data.jul_ci = c_i;
	julia_init_1(&data);
	create_img(&data, 2);
	push_img(&data);
	mlx_hook(data.win, 17, 1L << 2, kill_func, &data);
	mlx_hook(data.win, 2, 1L << 0, key_func, &data);
	mlx_mouse_hook(data.win, mouse_func, &data);
	mlx_loop(data.mlx);
}
