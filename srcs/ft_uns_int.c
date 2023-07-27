/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:30:52 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:01:56 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_left_side_u(t_data *arg, char *str, int len)
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

void	ft_right_side_u(t_data *arg, char *str, int len)
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

void	ft_convert_u(t_data *arg)
{
	uintmax_t	conv;
	int			len;
	char		*str;

	conv = (unsigned int)va_arg(arg->ap, unsigned int);
	len = ft_nbrlen_unsg(conv, 10);
	if (arg->f[DOT] == 1 && arg->precis == 0 && conv == 0)
		len = 0;
	ft_parse_conv(arg, 1, len);
	str = ft_itoa_base_uns(conv, DECIMAL);
	if (arg->f[MINUS] == 1)
		ft_left_side_u(arg, str, len);
	else if (arg->f[MINUS] == 0)
		ft_right_side_u(arg, str, len);
	free(str);
}
