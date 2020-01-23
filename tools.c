/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 17:51:34 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double n, double a, double b, double a2, double b2)
{
	double	per_cent;

	per_cent = (n - a) / (b - a);
	return (a2 + (per_cent * (b2 - a2)));
}

int		ft_close(t_mlxparams *mlxparams)
{
	//must free
	(void)mlxparams;
	exit(0);
}

void	init(t_mlxparams *mlxparams)
{
	fill_fractal_infos(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
	draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

void	ft_switch(t_mlxparams *mlxparams)
{
	mlxparams->flag = mlxparams->flag == 1 ? 2 : 1;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
	draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

int	ft_mouse_move(int x, int y, t_mlxparams *mlxparams)
{
	x -= I_X0;
	y -= I_Y0;

	if (mlxparams->track_flag == 1 && x >= 0 && x <= I_LEN && y >= 0 && y <= I_LEN)
	{
		mlxparams->fractal_infos.z.x = map(x, (double)0, (double)I_WID,\
				mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax);
		mlxparams->fractal_infos.z.y = map(y, (double)0, (double)I_WID,\
				mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin);
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
	return (0);
}


void	change_state_of_track(t_mlxparams *mlxparams)
{
	mlxparams->track_flag = mlxparams->track_flag == 1 ? 0 : 1;
}

int		mouse_hook(int button, int x, int y, t_mlxparams *mlxparams)
{
	if (button == 4)
		centred_zoom_out((double)x, (double)y, mlxparams);
	else if (button == 5)
		centred_zoom_in((double)x, (double)y, mlxparams);
	else if (button == 1)
		change_state_of_track(mlxparams);
	return (0);
}

int		key_hook(int keycode, t_mlxparams *mlxparams)
{
	if (keycode == 53)
		ft_close(mlxparams);
	else if (keycode == 123)
		move_left(mlxparams);
	else if (keycode == 124)
		move_right(mlxparams);
	else if (keycode == 126)
		move_up(mlxparams);
	else if (keycode == 125)
		move_down(mlxparams);
	else if (keycode == 69)
		zoom_in(mlxparams);
	else if (keycode == 78)
		zoom_out(mlxparams);
	else if (keycode == 34)
		init(mlxparams);
	else if (keycode == 1)
		ft_switch(mlxparams);
	else if (keycode == 18)
		ft_color1(mlxparams);
	else if (keycode == 19)
		ft_color2(mlxparams);
	else if (keycode == 20)
		ft_color3(mlxparams);
	else if (keycode == 29)
		ft_color0(mlxparams);
	return (0);
}

