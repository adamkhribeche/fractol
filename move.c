/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:59:08 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 16:26:14 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    fill_mb_to_move_left(t_fractal_infos *fractal_infos)
{
	fractal_infos->xmax -= fractal_infos->len * SHIFT_PERCENT;
	fractal_infos->xmin -= fractal_infos->len * SHIFT_PERCENT;
}

static void    fill_mb_to_move_right(t_fractal_infos *fractal_infos)
{
	fractal_infos->xmax += fractal_infos->len * SHIFT_PERCENT;
	fractal_infos->xmin += fractal_infos->len * SHIFT_PERCENT;
}

static void    fill_mb_to_move_up(t_fractal_infos *fractal_infos)
{
	fractal_infos->ymax -= fractal_infos->len * SHIFT_PERCENT;
	fractal_infos->ymin -= fractal_infos->len * SHIFT_PERCENT;
}

static void    fill_mb_to_move_down(t_fractal_infos *fractal_infos)
{
	fractal_infos->ymax += fractal_infos->len * SHIFT_PERCENT;
	fractal_infos->ymin += fractal_infos->len * SHIFT_PERCENT;
}

void    move_left(t_mlxparams *mlxparams)
{
	fill_mb_to_move_left(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

void    move_right(t_mlxparams *mlxparams)
{
	fill_mb_to_move_right(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

void    move_up(t_mlxparams *mlxparams)
{
	fill_mb_to_move_up(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

void    move_down(t_mlxparams *mlxparams)
{
	fill_mb_to_move_down(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}
