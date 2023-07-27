/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:29:16 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:03:05 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_precis_star(t_data *arg)
{
	arg->precis = va_arg(arg->ap, int);
	while (arg->str[arg->pos] == '*')
		arg->pos++;
}

void	ft_precision(t_data *arg)
{
	if ((arg->str[arg->pos]) == '.')
	{
		arg->f[DOT] = 1;
		arg->pos++;
		if (arg->str[arg->pos] == '*')
			ft_precis_star(arg);
		else if (ft_isdigit(arg->str[arg->pos]))
			arg->precis = ft_atoi(&arg->str[arg->pos]);
		while (ft_isdigit(arg->str[arg->pos]))
		{
			arg->pos++;
			while (arg->str[arg->pos] == '*')
				arg->pos++;
		}
		if (arg->precis < 0)
			arg->f[DOT] = 0;
	}
}
