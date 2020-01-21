/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:03:56 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/21 14:12:15 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_color0(t_mlxparams *mlxparams)
{
	mlxparams->color1 = 0;
	mlxparams->color2 = 8;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    ft_color1(t_mlxparams *mlxparams)
{
	mlxparams->color1 = 4;
	mlxparams->color2 = 10;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    ft_color2(t_mlxparams *mlxparams)
{
	mlxparams->color1 = 8;
	mlxparams->color2 = 16;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}

void    ft_color3(t_mlxparams *mlxparams)
{
	mlxparams->color1 = 18;
	mlxparams->color2 = 0;
	ft_memset(mlxparams->fractal.image, 0, I_LEN * I_WID * 4);
	mlxparams->flag == 1 ? draw_mb(mlxparams) : draw_julia(mlxparams, -0.7375, -0.3375);
}
