/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:00:03 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/19 14:24:36 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# define W_LEN 905
# define W_WID 905
# define I_LEN 801
# define I_WID 801
# define I_X0 52
# define I_Y0 53
# define COLOR 0X00FFFFFF
# define COLOR1 0X00a0d0c5
# define COLOR2 0X00c2b85b
# define COLOR3 0X00e3985b
# define COLOR4 0X00e3df5b
# define TRUE 1
# define FALSE 0
# define ABS(v) ((v > 0) ? v : -v)

typedef struct	s_mlxparams
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			length_win;
	int			width_win;
	void		*img_ptr;
	int			*image;
	//int			length_img;
	//int			width_img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlxparams;

typedef struct	s_z
{
	double	x;
	double	y;
}				t_z;
/*
** ***************************************************************************
*/
	
double	map(double n, double a, double b, double a2, double b2);
void	fill_mlxparams(t_mlxparams *mlxparams);
int		put(int keycode, void *vartemp);
int		ft_close(void *param);
int		key_hook(int keycode, void *param);
void	put_cadre(t_mlxparams *mlxparams, int x, int y, int len);


#endif
