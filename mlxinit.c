/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/19 23:39:12 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->ptr = mlx_init();
	mlxparams->win = mlx_new_window(mlxparams->ptr, W_LEN, W_WID, "mlx 42");
	mlxparams->img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, I_LEN, I_WID);
	mlxparams->img.image = (int *)mlx_get_data_addr(mlxparams->img.img_ptr,\
	&mlxparams->img.bits_per_pixel, &mlxparams->img.size_line, &mlxparams->img.endian);
	mlxparams->img.image_x0 = I_X0;
	mlxparams->img.image_y0 = I_Y0;
}
