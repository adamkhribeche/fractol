/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:00:03 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/18 18:01:39 by nkhribec         ###   ########.fr       */
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
# define W_LEN 1000
# define W_WID 1000
# define I_LEN 500
# define I_WID 500
# define COLOR 0X00FFFFFF
# define TRUE 1
# define FALSE 0
# define ABS(v) ((v > 0) ? v : -v)

typedef struct	s_mapdim
{
	int		length;
	int		width;
}				t_mapdim;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		v;
}				t_point;

typedef struct	s_map
{
	t_point		*tab;
	t_mapdim	dim;
}				t_map;

typedef struct	s_mlxxparams
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			length_win;
	int			width_win;
	void		*img_ptr;
	int			*image;
	int			length_img;
	int			width_img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlxparams;

/*
** ***************************************************************************
*/

typedef	struct	s_draw_vars
{
	int	edx;
	int	pdx;
	int	dx;
	int	dy;
	int	incrx;
	int	incry;
	int	i;
	int	index;
}				t_draw_vars;

typedef struct	s_hook
{
	t_mlxparams	*mlxparams;
	t_map		*map;
	t_point		proj_params[2];
}				t_hook;

void			fill_mlxparams(t_mlxparams *mlxparams);
int				put(int keycode, void *vartemp);
void			zoomin(t_map *map);
void			zoomout(t_map *map);
void			zoom(t_map *map);
void			get_params_to_center_isoproject(int *x, int *y, t_map *map);
void			get_params_to_center_parallelproject(int *x, int *y, \
				t_map *map);
/*
** in file : tools 2
*/

void			zoomout(t_map *map);
void			zoomin(t_map *map);
int				min(int a, int b, int c, int d);
int				max(int a, int b, int c, int d);

int				ft_exit(void *hook);

#endif
