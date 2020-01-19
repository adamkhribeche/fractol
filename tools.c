/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:48:43 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/19 15:03:15 by nkhribec         ###   ########.fr       */
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
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j, COLOR);
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j + 1, COLOR);
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
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i, j, COLOR);
		mlx_pixel_put(mlxparams->mlx_ptr, mlxparams->mlx_win, i + 1, j, COLOR);
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

