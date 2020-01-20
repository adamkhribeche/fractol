/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:00:03 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/20 22:16:31 by nkhribec         ###   ########.fr       */
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
# define CADRE_X0 50
# define CADRE_Y0 50
# define CADRE_LEN 806
# define I_X0 52
# define I_Y0 53
# define ITERATION 40
# define COLOR 0X00FFFFFF
# define TRUE 1
# define FALSE 0
# define ABS(v) ((v > 0) ? v : -v)

typedef struct	s_mb_infos
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	len;
}				t_mb_infos;

typedef struct	s_img
{
	void		*img_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct		s_mlxparams
{
	void			*ptr;
	void			*win;
	t_img			fractal;
	t_img			img_clean;
	t_mb_infos		mb_infos;
}					t_mlxparams;

typedef struct	s_z
{
	double	x;
	double	y;
}				t_z;

/*typedef struct	s_param
{
	t_mlxparams mlxparams;
}				t_param;*/

/*
** ***************************************************************************
*/

void	draw(t_mlxparams *mlxparams);
void	fill_mb_infos(t_mb_infos *mb_infos);
double	map(double n, double a, double b, double a2, double b2);
void	fill_mlxparams(t_mlxparams *mlxparams);
int		put(int keycode, void *vartemp);
int		ft_close(void *param);
int		key_hook(int keycode, void *param);
void	put_cadre(t_mlxparams *mlxparams, int x, int y, int len);


#endif
