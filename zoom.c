/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:52:35 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 14:12:06 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    fill_mb_to_zoomin(t_mb_infos *mb_infos)
{
	mb_infos->xmax *= 0.8;// 70 per cent
	mb_infos->xmin *= 0.8;
	mb_infos->ymax *= 0.8;
	mb_infos->ymin *= 0.8;
	mb_infos->len = (mb_infos->xmax - mb_infos->xmin);
}

static void    fill_mb_to_zoomout(t_mb_infos *mb_infos)
{
	mb_infos->xmax /= 0.8;
	mb_infos->xmin /= 0.8;
	mb_infos->ymax /= 0.8;
	mb_infos->ymin /= 0.8;
	mb_infos->len = (mb_infos->xmax - mb_infos->xmin);
}

void    zoom_out(t_mlxparams *mlxparams)
{
	fill_mb_to_zoomout(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    zoom_in(t_mlxparams *mlxparams)
{
	fill_mb_to_zoomin(&mlxparams->mb_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}
