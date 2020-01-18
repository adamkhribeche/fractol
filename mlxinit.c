/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/18 17:08:12 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->mlx_ptr = mlx_init();
	mlxparams->mlx_win = mlx_new_window(mlxparams->mlx_ptr, W_LEN, W_WID, "mlx 42");
	mlxparams->img_ptr = (int*)mlx_new_image(mlxparams->mlx_ptr, I_LEN, I_WID);
	mlxparams->length_img = I_LEN;
	mlxparams->width_img = I_WID;
	mlxparams->image = (int *)mlx_get_data_addr(mlxparams->img_ptr,\
	&mlxparams->bits_per_pixel, &mlxparams->size_line, &mlxparams->endian);
}
