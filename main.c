/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:07:19 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/18 18:22:37 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_horizental(t_mlxparams *mlxparams, int x, int y, int len)
{
	int		i;
	int		j;

	i = x - 1;
	j = y;
	while (++i < len + x)
	{
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j, 0xffffff);
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j + 1, 0xffffff);
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
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j, 0xffffff);
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i + 1, j, 0xffffff);
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
	(void)param;
	exit(0);
}

int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
		ft_close(param);
	return (0);
}


void	mandelbrot(t_mlxparams *mlxparams)
{
	void *param;

	put_cadre(mlxparams, 200, 300, 500);

	mlx_key_hook(mlxparams->mlx_win, key_hook, param);
	mlx_hook(mlxparams->mlx_win, 17, 0, close, param);
	mlx_loop(mlxparams->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_mlxparams		*mlxparams;

	if (ac >= 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		mlxparams = malloc(sizeof(*mlxparams));
		fill_mlxparams(mlxparams);
		mandelbrot(mlxparams);
	}
	else
		ft_putendl("usage: fractol mandelbrot | julia");
	return (0);
}
