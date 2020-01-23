/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centred_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:58:01 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 17:48:28 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	centred_zoom_out(double x, double y, t_mlxparams *mlxparams)
{
	double xmin;
	double xmax;
	double ymin;
	double ymax;

	if (x >= 0 && x <= I_LEN && y >= 0 && y <= I_LEN)
	{
		x -= I_X0;
		y -= I_Y0;
		xmin = mlxparams->fractal_infos.xmin;
		xmax = mlxparams->fractal_infos.xmax;
		ymin = mlxparams->fractal_infos.ymin;
		ymax = mlxparams->fractal_infos.ymax;
		x = map(x, (double)0, (double)I_WID, xmin, xmax);
		y = map(y, (double)0, (double)I_WID, ymax, ymin);
		mlxparams->fractal_infos.xmin = x - (x - xmin) * ZMOUT_PERCENT;
		mlxparams->fractal_infos.xmax = x + (xmax - x) * ZMOUT_PERCENT;
		mlxparams->fractal_infos.ymax =  y + (ymax - y) * ZMOUT_PERCENT;
		mlxparams->fractal_infos.ymin = y - (y - ymin) * ZMOUT_PERCENT;
		mlxparams->fractal_infos.len *= ZMOUT_PERCENT;
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
}

void	centred_zoom_in(double x, double y, t_mlxparams *mlxparams)
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;

	if (x > 0 && x < I_LEN && y > 0 && y < I_LEN)
	{
		x -= I_X0;
		y -= I_Y0;
		xmin = mlxparams->fractal_infos.xmin;
		xmax = mlxparams->fractal_infos.xmax;
		ymin = mlxparams->fractal_infos.ymin;
		ymax = mlxparams->fractal_infos.ymax;
		x = map(x, (double)0, (double)I_WID, xmin, xmax);
		y = map(y, (double)0, (double)I_WID, ymax, ymin);
		mlxparams->fractal_infos.xmin = x - (x - xmin) * ZMIN_PERCENT;
		mlxparams->fractal_infos.xmax = x + (xmax - x) * ZMIN_PERCENT;
		mlxparams->fractal_infos.ymax =  y + (ymax - y) * ZMIN_PERCENT;
		mlxparams->fractal_infos.ymin = y - (y - ymin) * ZMIN_PERCENT;
		mlxparams->fractal_infos.len *= ZMIN_PERCENT;
		ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
		mlxparams->flag == 1 ? draw_mb(mlxparams) :\
		draw_julia(mlxparams, mlxparams->fractal_infos.z.x, mlxparams->fractal_infos.z.y);
	}
}

