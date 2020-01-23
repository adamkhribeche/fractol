/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:52:35 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 16:54:58 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    fill_fractal_data_to_zoom_in(t_fractal_infos *fractal_infos)
{
	fractal_infos->xmax *= ZMIN_PERCENT;// 90 per cent
	fractal_infos->xmin *= ZMIN_PERCENT;
	fractal_infos->ymax *= ZMIN_PERCENT;
	fractal_infos->ymin *= ZMIN_PERCENT;
	fractal_infos->len = (fractal_infos->xmax - fractal_infos->xmin);
}

static void    fill_fractal_data_to_zoomout(t_fractal_infos *fractal_infos)
{
	fractal_infos->xmax *= ZMOUT_PERCENT;
	fractal_infos->xmin *= ZMOUT_PERCENT;
	fractal_infos->ymax *= ZMOUT_PERCENT;
	fractal_infos->ymin *= ZMOUT_PERCENT;
	fractal_infos->len = (fractal_infos->xmax - fractal_infos->xmin);
}

void    zoom_out(t_mlxparams *mlxparams)
{
	fill_fractal_data_to_zoomout(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
	draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}

void    zoom_in(t_mlxparams *mlxparams)
{
	fill_fractal_data_to_zoom_in(&mlxparams->fractal_infos);
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) :\
	draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
}
