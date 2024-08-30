/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:30 by gusgonza          #+#    #+#             */
/*   Updated: 2024/08/30 23:33:30 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "MLX42.h"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		size_line;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef	struct s_fractol
{
	t_img		img;
	t_complex	*yow;
	
}	t_fractol;


#endif