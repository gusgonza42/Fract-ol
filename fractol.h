/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:11:36 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/28 13:11:39 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERRORMSSG1 "Please, enter a valid fractal name: \n"
# define ERRORMSSG2 "\t\"mandelbrot\"\n"
# define ERRORMSSG3 "\t\"julia <val_1> <val_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

/*<-- COLORS -->*/
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

/*<-- SPECIAL COLORS -->*/
# define MAGENTABURST 0xFF00FF
# define LIMESHOCK 0x32CD32
# define NEON_ORANGE 0xFF4500
# define ACID_GREEN 0xB0FF00
# define ELECTRIC_BLUE 0x7DF9FF
# define ULTRA_VIOLET 0x6A0DAD
# define PSY_YELLOW 0xFFFF33
# define FLUORESCENT_PINK 0xFF1493
# define LASER_LEMON 0xFFFF66
# define HOT_PINK 0xFF69B4
# define RADIANT_RED 0xFF5555

/* KEY CODES*/
# define K_ESC 0xff1b
# define K_LEFT 0xff51
# define K_UP 0xff52
# define K_RIGHT 0xff53
# define K_DOWN 0xff54
# define K_PLUS 65451
# define K_MINUS 65453

/*<-- STRUCTS -->*/
typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_val;
	int		iter_def;
	double	x_shift;
	double	y_shift;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

// Init
void		fractal_init(t_fractal *fractal);
// Math
double		mapscale(double unsc_num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	sqr_complex(t_complex z);
double		ft_atoidbl(char *str);
int			ft_chkr(char *str);
// Render
void		fractal_render(t_fractal *fractal);
// Events
int			key_handler(int keycode, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			motion_handler(int x, int y, t_fractal *frt);

#endif
