/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:43:08 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 12:44:04 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include "./libft/libft.h"

# define JUL_ARGZ " enter correct values"
# define NB_ARGZ "incorrect number of arguments\n"

typedef struct fract_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	img_x;
	double	img_y;
	double	zoom;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	jul_cr;
	double	jul_ci;
	int		fract_type;
	int		max_iter;
}			t_data;

int		win_size(char val, int opt);
void	error_check(int argc, char **argv);
void	mandel(void);
void	draw_mandel(t_data *data);
void	mandel_calc(t_data *data, int x, int y);
void	mandel_init_2(t_data	*data, int x, int y);
void	mandel_init_1(t_data *data);
int		value_check(t_data *data);
void	create_img(t_data *data, int opt);
void	push_img(t_data *data);
void	img_pxl_put(t_data *data, int x, int y, int color);
int		key_func(int keycode, void *param);
int		kill_func(void *param);
int		mouse_func(int keycode, int x, int y, void *param);
void	zoom(t_data *data, int x, int y, int opt);
int		new_values(t_data *data, int x, int y, int opt);
int		shade(int x, int y);
void	julia(double c_r, double c_i);
void	julia_calc(t_data *data, int x, int y);
void	draw_julia(t_data *data);
void	julia_init_2(t_data	*data, int x, int y);
void	julia_init_1(t_data *data);
void	check_jul_argz(int argc, char **argv);
void	error_check(int argc, char **argv);
void	scan_jul_arg(char *arg);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move(int keycode, t_data *data);
void	print_argz_list(void);

#endif
