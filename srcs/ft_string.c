/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:30:17 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:01:52 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_write_s(t_data *arg, char *str, int pad, int len)
{
	char flag;

	if (arg->f[MINUS] == 0)
	{
		flag = (arg->f[ZERO] == 1) ? '0' : ' ';
		if (pad > 0)
			ft_write_pad(pad, &flag);
	}
	write(1, str, len);
	if (arg->f[MINUS] == 1)
	{
		if (pad > 0)
			ft_write_pad(pad, " ");
	}
	return (pad + len);
}

void	ft_convert_s(t_data *arg)
{
	char	*str;
	int		len;
	int		pad;

	pad = 0;
	str = (char *)va_arg(arg->ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (arg->f[DOT] && len > arg->precis)
		len = arg->precis;
	if (arg->width > len)
		pad = arg->width - len;
	arg->return_val += ft_write_s(arg, str, pad, len);
}
