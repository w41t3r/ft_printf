/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:18:18 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:01:07 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_convert_c(t_data *arg)
{
	unsigned char	c;
	int				pad;
	char			flag;

	pad = 0;
	if (arg->str[arg->pos] == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(arg->ap, int);
	if (arg->width > 0)
		pad = arg->width - 1;
	if (arg->f[MINUS] == 0)
	{
		flag = (arg->f[ZERO] == 1) ? '0' : ' ';
		if (pad > 0)
			ft_write_pad(pad, &flag);
	}
	arg->return_val += write(1, &c, 1);
	if (arg->f[MINUS] == 1)
	{
		if (pad > 0)
			ft_write_pad(pad, " ");
	}
	arg->return_val += pad;
}
