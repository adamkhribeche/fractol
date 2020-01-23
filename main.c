/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:07:19 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 14:53:43 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_diverg_mb(double x, double y)
{
	t_z		z0;
	t_z		z;
	int		i;

	i = -1;
	z0.x = 0;
	z0.y = 0;
	while (++i < ITERATION)
	{
		z.x = (z0.x * z0.x) - (z0.y * z0.y) + x;
		z.y = (2 * (z0.x * z0.y)) + y;
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			return (i);
		}
		z0.x = z.x;
		z0.y = z.y;
	}
	return (0);
}

void	draw_mb(t_mlxparams *mlxparams)
{
	double		x;
	double		y;
	int			i;
	int			ret;
	int			j;

	j = 0;
	while (j < I_WID)
	{
		i = 0;
		y = map(j, 0, I_WID, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin);
		while (i < I_LEN)
		{
			x = map(i, 0, I_LEN, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax);
			if ((ret = is_diverg_mb(x, y)))
			{
				mlxparams->fractal.image[i + (j * I_LEN)] =\
				((ret * 255 / ITERATION) << mlxparams->color1) +\
				((ret * 255 / ITERATION) << mlxparams->color2);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, I_X0, I_Y0);
}

int		is_diverg_julia(double x, double y, double a, double b)
{
	t_z		z0;
	t_z		z;
	int		i;

	i = -1;
	z0.x = x;
	z0.y = y;
	while (++i < ITERATION)
	{
		z.x = (z0.x * z0.x) - (z0.y * z0.y) + a;
		z.y = (2 * (z0.x * z0.y)) + b;
		if (((z.x * z.x) + (z.y * z.y)) > 4)
		{
			return (i);
		}
		z0.x = z.x;
		z0.y = z.y;
	}
	return (0);
}

void	draw_julia(t_mlxparams *mlxparams, double a, double b)
{
	double		x;
	double		y;
	int			i;
	int			ret;
	int			j;

	j = 0;
	while (j < I_WID)
	{
		i = 0;
		y = map(j, 0, I_WID, mlxparams->fractal_infos.ymax, mlxparams->fractal_infos.ymin);
		while (i < I_LEN)
		{
			x = map(i, 0, I_LEN, mlxparams->fractal_infos.xmin, mlxparams->fractal_infos.xmax);
			if ((ret = is_diverg_julia(x, y, a, b)))
			{
				mlxparams->fractal.image[i + (j * I_LEN)] = \
				((ret * 255 / ITERATION) << mlxparams->color1) +\
				((ret * 255 / ITERATION) << mlxparams->color2);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, I_X0, I_Y0);
}

void	draw(t_mlxparams *mlxparams)
{
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
	draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	mlx_mouse_hook(mlxparams->win, mouse_hook, mlxparams);
	mlx_key_hook(mlxparams->win, key_hook, mlxparams);
	mlx_hook(mlxparams->win, 17, 0, ft_close, mlxparams);
	mlx_hook(mlxparams->win, 6, 0, ft_mouse_move, mlxparams);
}

int		main(int ac, char **av)
{
	t_mlxparams		*mlxparams;
	int				flag;

	if (ac >= 2 && (((flag = ft_strcmp(av[1], "mandelbrot") + 1) == 1) ||\
				(flag = ft_strcmp(av[1], "julia") + 2) == 2))
	{
		mlxparams = malloc(sizeof(*mlxparams));
		fill_mlxparams(mlxparams, flag);
		draw(mlxparams);
		mlx_loop(mlxparams->ptr);
	}
	ft_putendl("usage: fractol mandelbrot | julia");
	return (0);
}
