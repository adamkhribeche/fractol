/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:00:03 by nkhribec          #+#    #+#             */
/*   Updated: 2020/01/23 16:59:04 by nkhribec         ###   ########.fr       */
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
# define CADRE_X0 50
# define CADRE_Y0 50
# define CADRE_LEN 806
# define ITERATION 50
# define SHIFT_PERCENT 0.03
# define ZMIN_PERCENT 0.9
# define ZMOUT_PERCENT 1.1
# define COLOR 0X00FFFFFF

typedef struct	s_z
{
	double	x;
	double	y;
}				t_z;

typedef struct	s_fractal_infos
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	len;
	t_z		z;
}				t_fractal_infos;

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
	int				flag;
	int				color1;
	int				color2;
	t_img			fractal;
	int				track_flag;
	t_fractal_infos		fractal_infos;
}					t_mlxparams;

/*
** ***************************************************************************
*/

void	centred_zoom_in(double x, double y, t_mlxparams *mlxparams);
void	centred_zoom_out(double x, double y, t_mlxparams *mlxparams);
int		mouse_hook(int button, int x, int y, t_mlxparams *mlxparams);
void    ft_color0(t_mlxparams *mlxparams);
void    ft_color1(t_mlxparams *mlxparams);
void    ft_color2(t_mlxparams *mlxparams);
void    ft_color3(t_mlxparams *mlxparams);
void    move_left(t_mlxparams *mlxparams);
void    move_right(t_mlxparams *mlxparams);
void    move_up(t_mlxparams *mlxparams);
void    move_down(t_mlxparams *mlxparams);
void    zoom_out(t_mlxparams *mlxparams);
void    zoom_in(t_mlxparams *mlxparams);
int		ft_mouse_move(int x, int y, t_mlxparams *mlxparams);
void	draw_mb(t_mlxparams *mlxparams);
void	draw_julia(t_mlxparams *mlxparams, double a, double b);
void	draw(t_mlxparams *mlxparams);
void	fill_fractal_infos(t_fractal_infos *fractal_infos);
double	map(double n, double a, double b, double a2, double b2);
void	fill_mlxparams(t_mlxparams *mlxparams, int flag);
int		put(int keycode, void *vartemp);
int		ft_close(t_mlxparams *mlxparams);
int		key_hook(int keycode, t_mlxparams *mlxparams);
void	put_cadre(t_mlxparams *mlxparams, int x, int y, int len);


#endif
