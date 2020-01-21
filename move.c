/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:59:08 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 14:12:22 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    fill_mb_to_move_left(t_mb_infos *mb_infos)
{
	mb_infos->xmax -= mb_infos->len * 0.03;
	mb_infos->xmin -= mb_infos->len * 0.03;
}

static void    fill_mb_to_move_right(t_mb_infos *mb_infos)
{
	mb_infos->xmax += mb_infos->len * 0.03;
	mb_infos->xmin += mb_infos->len * 0.03;
}

static void    fill_mb_to_move_up(t_mb_infos *mb_infos)
{
	mb_infos->ymax -= mb_infos->len * 0.03;
	mb_infos->ymin -= mb_infos->len * 0.03;
}

static void    fill_mb_to_move_down(t_mb_infos *mb_infos)
{
	mb_infos->ymax += mb_infos->len * 0.03;
	mb_infos->ymin += mb_infos->len * 0.03;
}

void    move_left(t_mlxparams *mlxparams)
{
	fill_mb_to_move_left(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    move_right(t_mlxparams *mlxparams)
{
	fill_mb_to_move_right(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    move_up(t_mlxparams *mlxparams)
{
	fill_mb_to_move_up(&mlxparams->mb_infos);
	mlx_put_image_to_window(mlxparams->ptr, mlxparams->win,\
			mlxparams->img_clean.img_ptr, I_X0, I_Y0);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    move_down(t_mlxparams *mlxparams)
{
	fill_mb_to_move_down(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}
