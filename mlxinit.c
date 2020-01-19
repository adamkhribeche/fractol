/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/19 10:37:33 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->mlx_ptr = mlx_init();
	mlxparams->mlx_win = mlx_new_window(mlxparams->mlx_ptr, W_LEN, W_WID, "mlx 42");
	mlxparams->img_ptr = (int*)mlx_new_image(mlxparams->mlx_ptr, I_LEN, I_WID);
	mlxparams->image = (int *)mlx_get_data_addr(mlxparams->img_ptr,\
	&mlxparams->bits_per_pixel, &mlxparams->size_line, &mlxparams->endian);
	//printf("%d\n", mlxparams->size_line);
	//printf("%d\n", mlxparams->bits_per_pixel);

	//exit(0);
}
