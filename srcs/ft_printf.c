/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:49:25 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:01:43 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

t_llist	*ft_insert(t_llist *list, char c, void (*pf)(t_data *arg))
{
	t_llist	*new_m;

	if (!(new_m = (t_llist*)malloc(sizeof(t_llist))))
		return (NULL);
	new_m->identifier = c;
	new_m->ptr_ft = pf;
	new_m->next = list;
	return (new_m);
}

int		ft_check_list(t_llist *list)
{
	t_llist *tmp;
	int		ret;

	if (list != NULL)
	{
		tmp = list->next;
		ret = 1;
		while (tmp)
		{
			ret++;
			tmp = tmp->next;
		}
		return (ret);
	}
	return (0);
}

void	ft_free_llist(t_llist *list)
{
	t_llist *tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return ;
}

t_llist	*ft_set_llist(t_llist *list)
{
	list = ft_insert(list, 'c', &ft_convert_c);
	list = ft_insert(list, '%', &ft_convert_c);
	list = ft_insert(list, 'i', &ft_convert_d);
	list = ft_insert(list, 'd', &ft_convert_d);
	list = ft_insert(list, 'u', &ft_convert_u);
	list = ft_insert(list, 's', &ft_convert_s);
	list = ft_insert(list, 'p', &ft_convert_p);
	list = ft_insert(list, 'x', &ft_convert_x);
	list = ft_insert(list, 'X', &ft_convert_x);
	if (ft_check_list(list) != 9)
	{
		ft_free_llist(list);
		return (NULL);
	}
	return (list);
}

int		ft_printf(const char *format, ...)
{
	t_data		arg;
	t_llist		*list_conv;

	arg.str = format;
	arg.pos = 0;
	arg.return_val = 0;
	if (format == NULL)
		return (-1);
	list_conv = NULL;
	if ((list_conv = ft_set_llist(list_conv)) == NULL)
		return (-1);
	va_start(arg.ap, format);
	ft_read_format(&arg, list_conv);
	va_end(arg.ap);
	ft_free_llist(list_conv);
	return (arg.return_val);
}
