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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 6) && ft_chkr(av[2])
		&& ft_chkr(av[3]))
	{
		fractal.name = av[1];
		fractal.julia_x = ft_atoidbl(av[2]);
		fractal.julia_y = ft_atoidbl(av[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERRORMSSG1, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
int	main(void)
{
	t_complex	c;
	t_complex	z;
	t_complex	tmp_real;

	z.real = 0;
	z.imaginary = 0;
	c.real = 0.285;
	c.imaginary = 0.01;
	for (int i = 0; i < 100; i++)
	{
		tmp_real.real = z.real;
		z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * tmp_real.real * z.imaginary + c.imaginary;
		printf("z.real: %f\nz.imaginary: %f\n", z.real, z.imaginary);
	}
}
*/
