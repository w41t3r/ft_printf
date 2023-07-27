/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:12 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:24 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_left_side_x(t_data *arg, char *str, int len)
{
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

void	ft_right_side_x(t_data *arg, char *str, int len)
{
	char c;

	if (arg->f[ZERO] == 1 && !arg->f[DOT])
		c = '0';
	else
		c = ' ';
	while (arg->width_pad > 0)
	{
		arg->return_val += write(1, &c, 1);
		arg->width_pad--;
	}
	while (arg->precis_pad > 0)
	{
		arg->return_val += write(1, "0", 1);
		arg->precis_pad--;
	}
	arg->return_val += write(1, str, len);
	return ;
}

void	ft_convert_x(t_data *arg)
{
	uintmax_t	conv;
	int			len;
	char		*str;

	conv = (unsigned int)va_arg(arg->ap, unsigned int);
	len = ft_nbrlen_unsg(conv, 16);
	if (arg->f[DOT] == 1 && arg->precis == 0 && conv == 0)
		len = 0;
	if (arg->str[arg->pos] == 'x')
		str = ft_itoa_base_uns(conv, HEXA_LOWER);
	else if (arg->str[arg->pos] == 'X')
		str = ft_itoa_base_uns(conv, HEXA_UPPER);
	ft_parse_conv(arg, 1, len);
	if (arg->f[MINUS] == 1)
		ft_left_side_x(arg, str, len);
	else if (arg->f[MINUS] == 0)
		ft_right_side_x(arg, str, len);
	free(str);
}
