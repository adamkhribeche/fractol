/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:08:07 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 03:57:54 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_cleantop_img(t_mlxparams *mlxparams)
{
	mlxparams->cleantop_img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, W_LEN, CADRE_Y0);
	mlxparams->cleantop_img.image = (int *)mlx_get_data_addr(mlxparams->cleantop_img.img_ptr,\
	&mlxparams->cleantop_img.bits_per_pixel, &mlxparams->cleantop_img.size_line,\
	&mlxparams->cleantop_img.endian);
}

void	set_cleandown_img(t_mlxparams *mlxparams)
{
	mlxparams->cleandown_img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, W_LEN, CADRE_Y0);
	mlxparams->cleandown_img.image = (int *)mlx_get_data_addr(mlxparams->cleandown_img.img_ptr,\
	&mlxparams->cleandown_img.bits_per_pixel, &mlxparams->cleandown_img.size_line,\
	&mlxparams->cleandown_img.endian);
}

void	set_cleanleft_img(t_mlxparams *mlxparams)
{
	mlxparams->cleanleft_img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, CADRE_X0, CADRE_LEN);
	mlxparams->cleanleft_img.image = (int *)mlx_get_data_addr(mlxparams->cleanleft_img.img_ptr,\
	&mlxparams->cleanleft_img.bits_per_pixel, &mlxparams->cleanleft_img.size_line,\
	&mlxparams->cleanleft_img.endian);
}

void	set_cleanright_img(t_mlxparams *mlxparams)
{
	mlxparams->cleanright_img.img_ptr = (int*)mlx_new_image(mlxparams->ptr, CADRE_X0, CADRE_LEN);
	mlxparams->cleanright_img.image = (int *)mlx_get_data_addr(mlxparams->cleanright_img.img_ptr,\
	&mlxparams->cleanright_img.bits_per_pixel, &mlxparams->cleanright_img.size_line,\
	&mlxparams->cleanright_img.endian);
}

void	fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->ptr = mlx_init();
	mlxparams->win = mlx_new_window(mlxparams->ptr, W_LEN, W_WID, "mlx 42");
	mlxparams->fractal.img_ptr = (int*)mlx_new_image(mlxparams->ptr, I_LEN, I_WID);
	mlxparams->fractal.image = (int *)mlx_get_data_addr(mlxparams->fractal.img_ptr,\
	&mlxparams->fractal.bits_per_pixel, &mlxparams->fractal.size_line, &mlxparams->fractal.endian);
	mlxparams->fractal.image_x0 = I_X0;
	mlxparams->fractal.image_y0 = I_Y0;
	set_cleantop_img(mlxparams);
	set_cleandown_img(mlxparams);
	set_cleanleft_img(mlxparams);
	set_cleanright_img(mlxparams);
}
