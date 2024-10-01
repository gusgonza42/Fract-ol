/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:12:20 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/28 13:12:23 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_fractal(t_fractal *fractal);
void	print_usage_and_exit(void);

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		fractal.name = av[1];
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 6) && ft_chkr(av[2])
		&& ft_chkr(av[3]))
	{
		fractal.name = av[1];
		fractal.julia_x = ft_atoidbl(av[2]);
		fractal.julia_y = ft_atoidbl(av[3]);
	}
	else
	{
		print_usage_and_exit();
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}

void	print_usage_and_exit(void)
{
	ft_putstr_fd(ERRORMSSG1, 2);
	ft_putstr_fd(ERRORMSSG2, 2);
	ft_putstr_fd(ERRORMSSG3, 2);
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}
