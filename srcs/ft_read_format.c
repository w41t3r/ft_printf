/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:00:29 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:41 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_chr_percent(t_data *arg, int c)
{
	arg->start = arg->pos;
	while (arg->str[arg->pos] != '\0')
	{
		if (arg->str[arg->pos] == (char)c)
			return (1);
		arg->end++;
		arg->pos++;
	}
	if (arg->str[arg->pos] == '\0' && c == '\0')
		return (0);
	return (0);
}

void	ft_init(t_data *arg)
{
	arg->start = 0;
	arg->end = 0;
	arg->width = 0;
	arg->precis = 0;
	arg->width_pad = 0;
	arg->precis_pad = 0;
	arg->f[MINUS] = 0;
	arg->f[ZERO] = 0;
	arg->f[DOT] = 0;
}

int		ft_read_format(t_data *arg, t_llist *list_conv)
{
	ft_init(arg);
	if (ft_chr_percent(arg, '%') == 1)
	{
		ft_printcar(arg);
		arg->pos++;
		ft_parse(arg, list_conv);
		if (arg->str[arg->pos] == '\0')
			return (arg->return_val);
		arg->pos++;
		return (ft_read_format(arg, list_conv));
	}
	else
		ft_printcar(arg);
	return (0);
}
