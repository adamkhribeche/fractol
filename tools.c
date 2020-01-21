/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 14:06:15 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double n, double a, double b, double a2, double b2)
{
	double	per_cent;

	per_cent = (n - a) / (b - a);
	return (a2 + (per_cent * (b2 - a2)));
}

int		ft_close(void *param)
{
	//must free
	(void)param;
	exit(0);
}

void	init(t_mlxparams *mlxparams)
{
	fill_mb_infos(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void	ft_switch(t_mlxparams *mlxparams)
{
	mlxparams->flag = mlxparams->flag == 1 ? 2 : 1;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

int	ft_mouse_move(int x, int y, t_mlxparams *mlxparams)
{
	float a;
	float b;

	x -= I_X0;
	y -= I_Y0;
	a = map(x, 0, I_WID, mlxparams->mb_infos.xmin, mlxparams->mb_infos.xmax);
	b = map(y, 0, I_WID, mlxparams->mb_infos.ymin, mlxparams->mb_infos.ymax);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, a, b);
	return (0);
}

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
		ft_close(param);
	else if (keycode == 123)
		move_left(((t_mlxparams*)param));
	else if (keycode == 124)
		move_right(param);
	else if (keycode == 126)
		move_up(param);
	else if (keycode == 125)
		move_down(param);
	else if (keycode == 69)
		zoom_in(param);
	else if (keycode == 78)
		zoom_out(param);
	else if (keycode == 34)
		init(param);
	else if (keycode == 1)
		ft_switch(param);
	else if (keycode == 18)
		ft_color1(param);
	else if (keycode == 19)
		ft_color2(param);
	else if (keycode == 20)
		ft_color3(param);
	else if (keycode == 29)
		ft_color0(param);
	return (0);
}

