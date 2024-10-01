/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:58:12 by gusgonza          #+#    #+#             */
/*   Updated: 2024/10/01 11:58:17 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * img->bits_per_pixel / 8);
    *(unsigned int *)(img->addr + offset) = color;
}

static void mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (ft_strncmp(fractal->name, "julia", 6))
    {
        c->re = fractal->julia_x    ;
        c->im = fractal->julia_y;
    }
    else
    {
        c->re = z->re;
        c->im = z->im;
    }
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.re = (mapscale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->x_shift;
    z.im = (mapscale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->y_shift;
    mandel_or_julia(&z, &c, fractal);
    while (i < fractal->iter_def)
    {
        z = sum_complex(sqr_complex(z), c);
        if ((z.re * z.re + z.im * z.im) > fractal->escape_val)
            {
                color = mapscale(i, BLACK, WHITE, fractal->iter_def);
                my_pixel_put(x, y, &fractal->img, color);
                return ;
            }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, WHITE);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
            fractal->img.img_ptr, 0, 0);
}
