/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:29:08 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:03:01 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_nbrlen_hex(unsigned long long n)
{
	int i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_left_side_p(t_data *arg, char *str, int len)
{
	arg->return_val += write(1, "0x", 2);
	arg->return_val += write(1, str, len);
	while (arg->width_pad > 0)
	{
		arg->return_val += write(1, " ", 1);
		arg->width_pad--;
	}
	return ;
}

void	ft_right_side_p(t_data *arg, char *str, int len)
{
	while (arg->width_pad > 0)
	{
		arg->return_val += write(1, " ", 1);
		arg->width_pad--;
	}
	arg->return_val += write(1, "0x", 2);
	arg->return_val += write(1, str, len);
	return ;
}

void	ft_convert_p(t_data *arg)
{
	unsigned long long	conv;
	int					len;
	int					ox_len;
	char				*str;

	conv = (unsigned long long)va_arg(arg->ap, void *);
	str = ft_itoa_base_uns(conv, HEXA_LOWER);
	ox_len = 2;
	len = ft_strlen(str);
	if (arg->f[DOT] == 1 && arg->precis == 0 && conv == 0)
		len = 0;
	ft_parse_conv(arg, conv, len + ox_len);
	if (arg->f[MINUS] == 1)
		ft_left_side_p(arg, str, len);
	else if (arg->f[MINUS] == 0)
		ft_right_side_p(arg, str, len);
	free(str);
}
