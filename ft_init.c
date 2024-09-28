/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:14:59 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/28 13:15:01 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_printf("Malloc error.\n");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->iter_def = 42;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 02, (1L << 0), key_handler, fractal);
	mlx_hook(fractal->mlx_window, 04, (1L << 2), mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 06, (1L << 6), motion_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, (1L << 17), close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
