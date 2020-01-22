/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 19:08:46 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_fractal_infos(t_fractal_infos *fractal_infos)
{
	fractal_infos->xmax = 2.;
	fractal_infos->xmin = -2.;
	fractal_infos->ymax = 2.;
	fractal_infos->ymin = -2.;
	fractal_infos->len = 4.;
	fractal_infos->z.x = -0.7375;
	fractal_infos->z.y = -0.3375;

}

void	set_fractal_img(t_mlxparams* mlxparams)
{
	mlxparams->fractal.img_ptr = (int*)mlx_new_image(mlxparams->ptr, I_LEN, I_WID);
	mlxparams->fractal.image = (int *)mlx_get_data_addr(mlxparams->fractal.img_ptr,\
	&mlxparams->fractal.bits_per_pixel, &mlxparams->fractal.size_line, &mlxparams->fractal.endian);
}

void	fill_mlxparams(t_mlxparams *mlxparams, int flag)
{
	mlxparams->ptr = mlx_init();
	mlxparams->win = mlx_new_window(mlxparams->ptr, W_LEN, W_WID, "mlx 42");
	mlxparams->flag = flag;
	mlxparams->color1 = 0;
	mlxparams->color2 = 8;
	mlxparams->track_flag = 1;
	fill_fractal_infos(&mlxparams->fractal_infos);
	set_fractal_img(mlxparams);
}
