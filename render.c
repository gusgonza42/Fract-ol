#include "fractol.h"


static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	offset = (y * img->line_len) = (x * (img->bpp / 8));
	*(unsigned int *) (img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	//PIXEL COOORDINATE X && SCALED TO FIT MANDEL NEDD
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(x, -2, +2, 0, HEIGHT);
//homw nay iterated z:2
//check if de point scaped
	while (i < fractal->iterations_definition)
	{
		//
		z = sum_complex(square_comple(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteracions_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	//we aare in mandelbrot given the iterations made
}

void	fractol_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel()
		}
	}
}
