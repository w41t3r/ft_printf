/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:31:07 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:09 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_widthstar(t_data *arg)
{
	if (arg->str[arg->pos] == '*')
	{
		arg->width = va_arg(arg->ap, int);
		if (arg->width < 0)
		{
			arg->f[MINUS] = 1;
			arg->width = -(arg->width);
			if (arg->f[ZERO] == 1)
				arg->f[ZERO] = 0;
		}
		while (arg->str[arg->pos] == '*')
			arg->pos++;
	}
}

void	ft_width(t_data *arg)
{
	while (arg->str[arg->pos] == ' ')
		arg->pos++;
	ft_widthstar(arg);
	if (ft_isdigit(arg->str[arg->pos]))
	{
		arg->width = ft_atoi(&arg->str[arg->pos]);
		while (ft_isdigit(arg->str[arg->pos]))
		{
			arg->pos++;
			while (arg->str[arg->pos] == '*')
				arg->pos++;
		}
	}
}
