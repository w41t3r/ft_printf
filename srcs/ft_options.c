/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:33 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 20:54:46 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_case1(t_data *arg, int conv, int len)
{
	arg->width_pad = arg->width - arg->precis;
	arg->precis_pad = arg->precis - len;
	if (conv < 0)
	{
		arg->width_pad--;
		arg->precis_pad++;
	}
}

void	ft_case2(t_data *arg, int conv, int len)
{
	arg->precis_pad = arg->precis - len;
	if (conv < 0)
		arg->precis_pad++;
}

void	ft_case3(t_data *arg, int len)
{
	arg->width_pad = arg->width - len;
}

void	ft_case4(t_data *arg, int conv, int len)
{
	arg->precis_pad = arg->precis - len;
	if (conv < 0)
		arg->precis_pad++;
}

void	ft_case5(t_data *arg, int len)
{
	(void)arg;
	(void)len;
	return ;
}
