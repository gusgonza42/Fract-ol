/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:37:00 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/25 12:27:32 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"


int main(int ac, char *av[])
{
	t_fractal fractal;

	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		printf("init()\n");
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);

	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO); //TODO
		exit (EXIT_FAILURE);
		malloc_error();

	}
	return (0);

}
