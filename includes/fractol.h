/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:30 by gusgonza          #+#    #+#             */
/*   Updated: 2024/06/20 16:26:11 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		size_line;
	int		endian;
	int		bpp;
}	t_img;

typedef	struct s_fractol
{

}	t_fractol;
