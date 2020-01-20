/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 17:15:07 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_mb_infos(t_mb_infos *mb_infos)
{
	mb_infos->xmax = 2.;
	mb_infos->xmin = -2.;
	mb_infos->ymax = 2.;
	mb_infos->ymin = -2.;
	mb_infos->pas = 4. / (I_LEN - 1.);
	mb_infos->rayon = 2.;
}

void	set_img_clean(t_mlxparams* mlxparams)
{
	mlxparams->img_clean.img_ptr = (int*)mlx_new_image(mlxparams->ptr, I_LEN, I_WID);
	mlxparams->img_clean.image = (int *)mlx_get_data_addr(mlxparams->img_clean.img_ptr,\
	&mlxparams->fractal.bits_per_pixel, &mlxparams->img_clean.size_line,\
	&mlxparams->img_clean.endian);
}

void	set_fractal_img(t_mlxparams* mlxparams)
{
	mlxparams->fractal.img_ptr = (int*)mlx_new_image(mlxparams->ptr, I_LEN, I_WID);
	mlxparams->fractal.image = (int *)mlx_get_data_addr(mlxparams->fractal.img_ptr,\
	&mlxparams->fractal.bits_per_pixel, &mlxparams->fractal.size_line, &mlxparams->fractal.endian);
}

void	fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->ptr = mlx_init();
	mlxparams->win = mlx_new_window(mlxparams->ptr, W_LEN, W_WID, "mlx 42");
	fill_mb_infos(&mlxparams->mb_infos);
	set_img_clean(mlxparams);
	set_fractal_img(mlxparams);
}
