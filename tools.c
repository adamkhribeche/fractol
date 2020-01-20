/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 19:40:18 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double n, double a, double b, double a2, double b2)
{
	double	m;

	m = (n - a) / (b - a);
	return (a2 + (m * (b2 - a2)));
}

void	draw_horizental(t_mlxparams *mlxparams, int x, int y, int len)
{
	int		i;
	int		j;

	i = x - 1;
	j = y;
	while (++i < len + x)
	{
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j, COLOR);
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j + 1, COLOR);
	}
}

void	draw_vertical(t_mlxparams *mlxparams, int x, int y, int len)
{
	int		i;
	int		j;

	i = x;
	j = y - 1;
	while (++j < len + y)
	{
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j, COLOR);
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i + 1, j, COLOR);
	}
}

void	put_cadre(t_mlxparams *mlxparams, int x, int y, int len)
{
	draw_horizental(mlxparams, x, y, len);
	draw_vertical(mlxparams, x, y, len);
	draw_horizental(mlxparams, x, y + len - 2, len);
	draw_vertical(mlxparams, x + len - 2, y, len);
}

int		ft_close(void *param)
{
	//must free
	(void)param;
	exit(0);
}

void	fill_mb_to_move_left(t_mb_infos *mb_infos)
{
	mb_infos->xmax += 10 * mb_infos->pas;
	mb_infos->xmin += 10 * mb_infos->pas;
	//mb_infos->xmax += 0.5;
	//mb_infos->xmin += 0.5;
}

void	fill_mb_to_move_right(t_mb_infos *mb_infos)
{
	mb_infos->xmax -= 10 * mb_infos->pas;
	mb_infos->xmin -= 10 * mb_infos->pas;
}

void	fill_mb_to_move_up(t_mb_infos *mb_infos)
{
	mb_infos->ymax += 10 * mb_infos->pas;
	mb_infos->ymin += 10 * mb_infos->pas;
}

void	fill_mb_to_move_down(t_mb_infos *mb_infos)
{
	mb_infos->ymax -= 10 * mb_infos->pas;
	mb_infos->ymin -= 10 * mb_infos->pas;
}

void	move_left(t_mlxparams *mlxparams)
{
	fill_mb_to_move_left(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	move_right(t_mlxparams *mlxparams)
{
	fill_mb_to_move_right(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	move_up(t_mlxparams *mlxparams)
{
	fill_mb_to_move_up(&mlxparams->mb_infos);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->img_clean.img_ptr, I_X0, I_Y0);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	move_down(t_mlxparams *mlxparams)
{
	fill_mb_to_move_down(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	init(t_mlxparams *mlxparams)
{
	fill_mb_infos(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	fill_mb_to_zoomin(t_mb_infos *mb_infos)
{
	mb_infos->xmax *= 0.7;// 70 per cent
	mb_infos->xmin *= 0.7;
	mb_infos->ymax *= 0.7;
	mb_infos->ymin *= 0.7;
	mb_infos->pas = (mb_infos->xmax - mb_infos->xmin) / (I_LEN - 1.);
}

void	fill_mb_to_zoomout(t_mb_infos *mb_infos)
{
	mb_infos->xmax *= 1.3;// 70 per cent
	mb_infos->xmin *= 1.3;
	mb_infos->ymax *= 1.3;
	mb_infos->ymin *= 1.3;
	mb_infos->pas = (mb_infos->xmax - mb_infos->xmin) / (I_LEN - 1.);
}

void	zoom_out(t_mlxparams *mlxparams)
{
	fill_mb_to_zoomout(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
}

void	zoom_in(t_mlxparams *mlxparams)
{
	fill_mb_to_zoomin(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	draw(mlxparams);
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
	return (0);
}

