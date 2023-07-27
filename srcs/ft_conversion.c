/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:46:19 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:02:15 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_conversion(t_data *arg, t_llist *list_conv)
{
	t_llist	*tmp_list;

	tmp_list = list_conv;
	while (tmp_list != NULL)
	{
		if (tmp_list->identifier == arg->str[arg->pos])
		{
			tmp_list->ptr_ft(arg);
			return ;
		}
		if (tmp_list)
			tmp_list = tmp_list->next;
	}
}
