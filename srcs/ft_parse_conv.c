/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:42 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:53 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_parse1(t_data *a, int co, int le)
{
	if (le <= a->precis)
		(a->width > a->precis) ? ft_case1(a, co, le) : ft_case2(a, co, le);
	else
		ft_case3(a, le);
}

void	ft_parse2(t_data *arg, int conv, int len)
{
	if (len <= arg->precis)
		ft_case4(arg, conv, len);
	else
		ft_case5(arg, len);
}

void	ft_parse_conv(t_data *arg, int conv, int len)
{
	if (len < arg->width)
		ft_parse1(arg, conv, len);
	else
		ft_parse2(arg, conv, len);
}
