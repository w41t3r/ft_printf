/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:39:22 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:20 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_flags(t_data *arg)
{
	while (ft_strchr("-0", arg->str[arg->pos]))
	{
		if ((arg->str[arg->pos]) == '-')
			arg->f[MINUS] = 1;
		else if ((arg->str[arg->pos]) == '0')
			arg->f[ZERO] = 1;
		arg->pos++;
		if (arg->f[MINUS] == 1)
			arg->f[ZERO] = 0;
	}
}
