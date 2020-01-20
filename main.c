/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:07:19 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 22:17:30 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_diverg(double x, double y)
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
int get_color(int a, int b)
{
	return ((a << 0) | (b << 8));
}
void	draw(t_mlxparams *mlxparams)
{
	double		x;
	double		y;
	int			i;
	int			ret;
	int			j;
	double 		a;
	int			bright;

	j = 0;
	while (j < I_WID)
	{
		i = 0;
		y = map(j, 0, I_WID, mlxparams->mb_infos.ymin, mlxparams->mb_infos.ymax);
		while (i < I_LEN)
		{
			x = map(i, 0, I_LEN, mlxparams->mb_infos.xmin, mlxparams->mb_infos.xmax);
			if ((ret = is_diverg(x, y)))
			{
				a = map(ret, 0, 100, 0, 1);
				bright = map(sqrt(a), 0, 1, 0, 255);
				mlxparams->fractal.image[i + (j * I_LEN)] = get_color(bright, bright);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
		mlxparams->fractal.img_ptr, I_X0, I_Y0);
}

void	mandelbrot(t_mlxparams *mlxparams)
{
	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	draw(mlxparams);
	mlx_key_hook(mlxparams->win, key_hook, mlxparams);
	mlx_hook(mlxparams->win, 17, 0, ft_close, mlxparams);
}

int		main(int ac, char **av)
{
	t_mlxparams		*mlxparams;

	if (ac >= 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		mlxparams = malloc(sizeof(*mlxparams));
		fill_mlxparams(mlxparams);
		mandelbrot(mlxparams);
		mlx_loop(mlxparams->ptr);
	}
	else
		ft_putendl("usage: fractol mandelbrot | julia");
	return (0);
}
