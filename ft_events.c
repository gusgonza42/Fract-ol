/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:24:23 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/28 14:30:14 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_hander(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == K_ESC)
		close_handler(fractal);
	else if (keycode == K_LEFT)
		fractal->x_shift -= (0.5 * fractal->zoom);
	else if (keycode == K_RIGHT)
		fractal->x_shift += (0.5 * fractal->zoom);
	else if (keycode == K_UP)
		fractal->y_shift += (0.5 * fractal->zoom);
	else if (keycode == K_DOWN)
		fractal->y_shift -= (0.5 * fractal->zoom);
	else if (keycode == K_PLUS)
		fractal->iter_def += 10;
	else if (keycode == K_MINUS)
		fractal->iter_def -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 0.95;
	else if (button == 5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	motion_handler(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		fractal->julia_x = (mapscale(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->x_shift;
		fractal->julia_y = (mapscale(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->y_shift;
	}
	fractal_render(fractal);
	return (0);
}
