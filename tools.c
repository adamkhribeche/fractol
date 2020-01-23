/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 16:12:04 by nkhribec         ###   ########.fr       */
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
	printf("ok\n");
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
		mlxparams->fractal_infos.z.x = map(x, 0, I_WID,\
				mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax);
		mlxparams->fractal_infos.z.y = map(y, 0, I_WID,\
				mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin);
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
	return (0);
}

void	centred_zoom_out(int x0, int y0, t_mlxparams *mlxparams)
{
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double len;
	double k  = 1.1;
	int 	px;
	int 	py;
	double	x;
	double	y;

	x0 -= I_X0;
	y0 -= I_Y0;
	px = x0;
	py = y0;
	//printf("px %d\n", px);
	//printf("py %d\n", py);
	xmin = mlxparams->fractal_infos.xmin;
	xmax = mlxparams->fractal_infos.xmax;
	ymin = mlxparams->fractal_infos.ymin;
	ymax = mlxparams->fractal_infos.ymax;
	//printf("out avant = %lf\n", mlxparams->fractal_infos.len);
	len = mlxparams->fractal_infos.len * k;
	//printf("%lf\n", len);
	if (x0 >= 0 && x0 <= I_LEN && y0 >= 0 && y0 <= I_LEN)
	{
		x = map(x0, 0, I_WID, xmin, xmax);
		y = map(y0, 0, I_WID, ymax, ymin);
		//printf("x %lf\n", x);
		//printf("y %lf\n", y);
		//x = map(x, xmin, xmax, x - iiifabs(0.9 * x), x + fabs(0.9 * (len - x)));
		//y = map(y, ymin, ymax, y - fabs(0.9 * y), y + fabs(0.9 * (len - y)));
		printf("------nouveau-------\n");
		printf("xmin %lf\n", mlxparams->fractal_infos.xmin);
		printf("xmax %lf\n", mlxparams->fractal_infos.xmax);
		printf("ymin %lf\n", mlxparams->fractal_infos.ymin);
		printf("ymax %lf\n", mlxparams->fractal_infos.ymax);
		printf("len %lf\n", mlxparams->fractal_infos.len);
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("px %d\n", px);
		printf("py %d\n", py);
		printf("I_LEN %d\n", I_LEN);
		printf("-------------\n");
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("----- px avant %d----\n", (int)map(x, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax, 0, I_LEN));
		printf("----- py avant %d----\n", (int)map(y, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin, 0, I_LEN));
		printf("-------------\n");
		/*mlxparams->fractal_infos.xmin = x - (((double)px / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.xmax = x + ((((I_LEN - 1) - (double)px) / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.ymax = y + (((double)py / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.ymin = y - ((((I_LEN - 1) - (double)py) / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.len = len;*/
		mlxparams->fractal_infos.xmin = x - (x - xmin) * k;
		mlxparams->fractal_infos.xmax = x + (xmax - x) * k;
		mlxparams->fractal_infos.ymax =  y + (ymax - y) * k;
		mlxparams->fractal_infos.ymin = y - (y - ymin) * k;
		mlxparams->fractal_infos.len = len;

		printf("-------------\n");
		printf("xmin %lf\n", mlxparams->fractal_infos.xmin);
		printf("xmax %lf\n", mlxparams->fractal_infos.xmax);
		printf("ymin %lf\n", mlxparams->fractal_infos.ymin);
		printf("ymax %lf\n", mlxparams->fractal_infos.ymax);
		printf("len %lf\n", mlxparams->fractal_infos.len);
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("-------------\n");
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("----- px %d----\n", (int)map(x, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax, 0, I_LEN));
		printf("----- py %d----\n", (int)map(y, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin, 0, I_LEN));
		printf("-------------\n");
			//mlxparams->fractal_infos.xmax - mlxparams->fractal_infos.xmin;
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
}

void	centred_zoom_in(int x0, int y0, t_mlxparams *mlxparams)
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	len;
	double 	k = 0.9;
	int 	px;
	int 	py;
	double	x;
	double	y;


	x0 -= I_X0;
	y0 -= I_Y0;
	px = x0;
	py = y0;
	//printf("px %d\n", px);
	//printf("py %d\n", py);
	xmin = mlxparams->fractal_infos.xmin;
	xmax = mlxparams->fractal_infos.xmax;
	ymin = mlxparams->fractal_infos.ymin;
	ymax = mlxparams->fractal_infos.ymax;
	//printf("in avant = %lf\n", mlxparams->fractal_infos.len);
	len = mlxparams->fractal_infos.len * k;
	//printf("%lf\n", len);
	if (x0 > 0 && x0 < I_LEN && y0 > 0 && y0 < I_LEN)
	{
		x = map(x0, 0, I_WID, xmin, xmax);
		y = map(y0, 0, I_WID, ymax, ymin);
		//printf("x %lf\n", x);
		//printf("y %lf\n", y);
		//x = map(x, xmin, xmax, x - fabs(0.9 * x), x + fabs(0.9 * (len - x)));
		//y = map(y, ymin, ymax, y - fabs(0.9 * y), y + fabs(0.9 * (len - y)));
		/*mlxparams->fractal_infos.xmin = x - fabs((x - xmin) / 0.9);
		mlxparams->fractal_infos.xmax = x + fabs((xmax - x) / 0.9);
		mlxparams->fractal_infos.ymin = y - fabs((y - ymin) / 0.9);
		mlxparams->fractal_infos.ymax = y + fabs((ymax - y) / 0.9);*/
		printf("------nouveau-------\n");
		printf("xmin %lf\n", mlxparams->fractal_infos.xmin);
		printf("xmax %lf\n", mlxparams->fractal_infos.xmax);
		printf("ymin %lf\n", mlxparams->fractal_infos.ymin);
		printf("ymax %lf\n", mlxparams->fractal_infos.ymax);
		printf("len %lf\n", mlxparams->fractal_infos.len);
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("px %d\n", px);
		printf("py %d\n", py);
		printf("I_LEN %d\n", I_LEN);
		printf("-------------\n");
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("----- avant px %d----\n", (int)map(x, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax, 0, I_LEN));
		printf("----- avant py %d----\n",(int)map(y, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin, 0, I_LEN));
		printf("-------------\n");
		/*mlxparams->fractal_infos.xmin = x - (((double)px / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.xmax = x + ((((I_LEN - 1) -(double)px) / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.ymax = y + (((double)py / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.ymin = y - ((((I_LEN - 1) -(double)py) / (I_LEN - 1)) * len);
		mlxparams->fractal_infos.len = len;*/
		mlxparams->fractal_infos.xmin = x - (x - xmin) * k;
		mlxparams->fractal_infos.xmax = x + (xmax - x) * k;
		mlxparams->fractal_infos.ymax =  y + (ymax - y) * k;
		mlxparams->fractal_infos.ymin = y - (y - ymin) * k;
		mlxparams->fractal_infos.len = len;
		printf("-------------\n");
		printf("xmin %lf\n", mlxparams->fractal_infos.xmin);
		printf("xmax %lf\n", mlxparams->fractal_infos.xmax);
		printf("ymin %lf\n", mlxparams->fractal_infos.ymin);
		printf("ymax %lf\n", mlxparams->fractal_infos.ymax);
		printf("len %lf\n", mlxparams->fractal_infos.len);
		printf("-------------\n");
		printf("x %lf\n", x);
		printf("y %lf\n", y);
		printf("----- px %d----\n", (int)map(x, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax, 0, I_LEN));
		printf("----- py %d----\n", (int)map(y, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin, 0, I_LEN));
		printf("-------------\n");



			//mlxparams->fractal_infos.xmax - mlxparams->fractal_infos.xmin;
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
}

void	change_state_of_track(t_mlxparams *mlxparams)
{
	mlxparams->track_flag = mlxparams->track_flag == 1 ? 0 : 1;
}
int		mouse_hook(int button, int x, int y, t_mlxparams *mlxparams)
{
	if (button == 4)
		centred_zoom_out(x, y, mlxparams);
	else if (button == 5)
		centred_zoom_in(x, y, mlxparams);
	else if (button == 1)
		change_state_of_track(mlxparams);
	return (0);
}

int		key_hook(int keycode, t_mlxparams *mlxparams)
{
	if (keycode == 53)
	{
		printf("ok\n");
		ft_close(mlxparams);
	}
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

