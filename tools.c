/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 03:57:06 by nkhribec         ###   ########.fr       */
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

void	clean_win(t_mlxparams *mlxparams)
{
	t_img img;

	img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, W_LEN, W_WID);
	img.image = (int *)mlx_get_data_addr(img.img_ptr,\
	&img.bits_per_pixel, &img.size_line, &img.endian);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			img.img_ptr, 0, 0);
}

void	clean_top(t_mlxparams *mlxparams)
{
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->cleantop_img.img_ptr, 0, 0);
}

void	clean_down(t_mlxparams *mlxparams)
{
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->cleandown_img.img_ptr, 0, CADRE_Y0 + CADRE_LEN);
}

void	clean_left(t_mlxparams *mlxparams)
{
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->cleanleft_img.img_ptr, 0, CADRE_Y0);
}

void	clean_right(t_mlxparams *mlxparams)
{
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->cleanright_img.img_ptr, CADRE_X0 + CADRE_LEN, CADRE_Y0);
}

void	clean_outsid(t_mlxparams *mlxparams)
{
	clean_top(mlxparams);
	clean_down(mlxparams);
	clean_left(mlxparams);
	clean_right(mlxparams);
}

void	move_left(t_mlxparams *mlxparams)
{
	mlxparams->fractal.image_x0 -= 6;
	clean_win(mlxparams);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, mlxparams->fractal.image_x0, mlxparams->fractal.image_y0);
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	clean_outsid(mlxparams);
}

void	move_right(t_mlxparams *mlxparams)
{
	mlxparams->fractal.image_x0 += 6;
	clean_win(mlxparams);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, mlxparams->fractal.image_x0, mlxparams->fractal.image_y0);
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	clean_outsid(mlxparams);
}

void	move_up(t_mlxparams *mlxparams)
{
	mlxparams->fractal.image_y0 -= 6;
	clean_win(mlxparams);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, mlxparams->fractal.image_x0, mlxparams->fractal.image_y0);
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	clean_outsid(mlxparams);
}

void	move_down(t_mlxparams *mlxparams)
{
	mlxparams->fractal.image_y0 += 6;
	clean_win(mlxparams);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, mlxparams->fractal.image_x0, mlxparams->fractal.image_y0);
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	clean_outsid(mlxparams);
}

void	init(t_mlxparams *mlxparams)
{
	mlxparams->fractal.image_x0 = I_X0;
	mlxparams->fractal.image_y0 = I_Y0;
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, mlxparams->fractal.image_x0, mlxparams->fractal.image_y0);
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
	else if (keycode == 34)
		init(param);
	return (0);
}

