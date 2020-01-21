/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cadre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:01:39 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 14:14:36 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    draw_horizental(t_mlxparams *mlxparams, int x, int y, int len)
{
	int     i;
	int     j;

	i = x - 1;
	j = y;
	while (++i < len + x)
	{
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j, COLOR);
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j + 1, COLOR);
	}
}

static void    draw_vertical(t_mlxparams *mlxparams, int x, int y, int len)
{
	int     i;
	int     j;

	i = x;
	j = y - 1;
	while (++j < len + y)
	{
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i, j, COLOR);
		mlx_pixel_put(mlxparams->ptr, mlxparams->win, i + 1, j, COLOR);
	}
}

void    put_cadre(t_mlxparams *mlxparams, int x, int y, int len)
{
	draw_horizental(mlxparams, x, y, len);
	draw_vertical(mlxparams, x, y, len);
	draw_horizental(mlxparams, x, y + len - 2, len);
	draw_vertical(mlxparams, x + len - 2, y, len);
}
