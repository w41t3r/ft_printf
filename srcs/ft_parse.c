/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:59 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:56 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_parse_specifier(t_data *arg)
{
	ft_flags(arg);
	ft_width(arg);
	ft_precision(arg);
}

void	ft_parse_identifier(t_data *arg, t_llist *list_conv)
{
	if (ft_strchr("cspdiouxX%", arg->str[arg->pos]))
		ft_conversion(arg, list_conv);
}

void	ft_parse(t_data *arg, t_llist *list_conv)
{
	if ((ft_strchr(FLAGS, arg->str[arg->pos])))
		ft_parse_specifier(arg);
	if ((ft_strchr(CONVERSIONS, arg->str[arg->pos])) == NULL)
	{
		if (arg->str[arg->pos] == '\0')
			return ;
		ft_putchar(arg->str[arg->pos]);
		arg->return_val++;
	}
	else if ((ft_strchr(CONVERSIONS, arg->str[arg->pos])) != NULL)
		ft_parse_identifier(arg, list_conv);
}
