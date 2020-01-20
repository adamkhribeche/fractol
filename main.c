/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:07:19 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 17:19:00 by nkhribec         ###   ########.fr       */
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
	while (++i < 100)
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
int get_color(int a, int b, int c)
{
	return ((a << 0) | (b << 8) | (c << 16));
}
void	draw(t_mlxparams *mlxparams)
{
	double		x;
	double		y;
	int			i;
	int			ret;
	//int			j;
	double 		a;
	int			bright;

	//y = -2.;
	y = mlxparams->mb_infos.ymin;
	i = 0;
	//j = 0;
	//pas = 0.005;
	while (y < mlxparams->mb_infos.ymax)
	{
		x = mlxparams->mb_infos.xmin;
		//x = -2.;
		while (x < mlxparams->mb_infos.xmax)
		{
			if (ABS(x) < 2. && ABS(y) < 2. && (ret = is_diverg(x, y)))
			{
				a = map(ret, 0, 100, 0, 1);
				bright = map(sqrt(a), 0, 1, 0, 255);
				mlxparams->fractal.image[i] = get_color(bright, bright, bright);
				//mlxparams->fractal.image[i] = bright;
			}
			//printf("%d\n", i);
			i++;
			x += mlxparams->mb_infos.pas;
		}
		//printf("%d\n", j++);
		//exit(0);
		y += mlxparams->mb_infos.pas;
	}
	//exit(0);
	//mlx_put_image_to_window(mlxparams->mlx_ptr, mlxparams->mlx_win,\
			mlxparams->img_ptr, I_X0, I_Y0);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->fractal.img_ptr, I_X0, I_Y0);
}

void	mandelbrot(t_mlxparams *mlxparams)
{
	t_param *param;

	put_cadre(mlxparams, CADRE_X0, CADRE_Y0, CADRE_LEN);
	draw(mlxparams);
	//mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, 52, 53, COLOR);
	mlx_key_hook(mlxparams->win, key_hook, mlxparams);
	mlx_hook(mlxparams->win, 17, 0, ft_close, param);
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
