/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:32:21 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/28 14:45:13 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mapscale(double unsc_num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * unsc_num / o_max + n_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	sqr_complex(t_complex z)
{
	t_complex	res;

	res.re = (z.re * z.re) - (z.im * z.im);
	res.im = 2 * z.re * z.im;
	return (res);
}

double	ft_atoidbl(char *str)
{
	long	int_part;
	double	decimal_part;
	double	pow;
	int		neg;

	int_part = 0;
	decimal_part = 0;
	neg = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9') && *str != '.')
		int_part = int_part * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		pow /= 10;
		decimal_part = decimal_part + (*str++ - '0') * pow;
	}
	return ((int_part + decimal_part) * neg);
}

int	ft_chkr(char *str)
{
	int	pass;

	pass = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str != '+' && *str != '-' && (*str < '0' && *str > '9'))
		pass = 0;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9') && *str != '.')
		str++;
	if (*str != '.' && *str != '\0')
		pass = 0;
	else if (*str == '.')
	{
		str++;
		while (*str != '\0' && pass == 1)
		{
			if (*str < '0' || *str > '9')
				pass = 0;
			str++;
		}
	}
	return (pass);
}
