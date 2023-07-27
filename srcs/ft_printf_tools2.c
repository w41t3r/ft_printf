/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:29:28 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:03:14 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_printcar(t_data *arg)
{
	if (arg->end > 0)
		write(1, &arg->str[arg->start], arg->end);
	arg->return_val += arg->end;
}

void	ft_write_pad(int pad, char *flag)
{
	while (pad > 0)
	{
		write(1, flag, 1);
		pad--;
	}
}

void	ft_write_blank(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	ft_write_zero(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}
