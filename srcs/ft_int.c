/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:22 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:29 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_left_side_d(t_data *arg, char *str, int len, int sign)
{
	if (sign == 1)
		arg->return_val += write(1, "-", 1);
	while (arg->precis_pad > 0)
	{
		arg->return_val += write(1, "0", 1);
		arg->precis_pad--;
	}
	arg->return_val += write(1, str, len);
	while (arg->width_pad > 0)
	{
		arg->return_val += write(1, " ", 1);
		arg->width_pad--;
	}
	return ;
}

void	ft_write_right(t_data *arg, char *str, int len, int sign)
{
	if (sign == 1)
		arg->return_val += write(1, "-", 1);
	while (arg->precis_pad > 0)
	{
		arg->return_val += write(1, "0", 1);
		arg->precis_pad--;
	}
	arg->return_val += write(1, str, len);
	return ;
}

void	ft_right_side_d(t_data *arg, char *str, int len, int sign)
{
	char c;

	if (arg->f[ZERO] == 1 && !arg->f[DOT])
	{
		c = '0';
		if (sign == 1)
		{
			arg->return_val += write(1, "-", 1);
			sign = 0;
		}
	}
	else
		c = ' ';
	while (arg->width_pad > 0)
	{
		arg->return_val += write(1, &c, 1);
		arg->width_pad--;
	}
	ft_write_right(arg, str, len, sign);
	return ;
}

void	ft_convert_d(t_data *arg)
{
	intmax_t	conv;
	int			len;
	char		*str;
	int			sign;

	conv = (int)va_arg(arg->ap, int);
	len = ft_nbrlen(conv, 10);
	if (arg->f[DOT] == 1 && arg->precis == 0 && conv == 0)
		len = 0;
	ft_parse_conv(arg, conv, len);
	sign = 0;
	if (conv < 0)
	{
		sign = 1;
		conv = -conv;
		len--;
	}
	str = ft_itoa_base_uns(conv, DECIMAL);
	if (arg->f[MINUS] == 1)
		ft_left_side_d(arg, str, len, sign);
	else if (arg->f[MINUS] == 0)
		ft_right_side_d(arg, str, len, sign);
	free(str);
}
