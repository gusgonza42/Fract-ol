#include "fractol.h"
#include "minilibx-linux/mlx.h"



static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *) (img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
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
	while (i < fractal->iterations_defintion)
	{
		//
		z = sum_complex(square_complex(z), c);
		// is the value scaped?
		// if hipotenuse > 2 i assume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;

	}
	//we aare in mandelbrot given the iterations made
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
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
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,fractal->mlx_window, fractal->img.img_ptr, 0, 0);

}
