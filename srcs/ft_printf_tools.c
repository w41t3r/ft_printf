/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:29:22 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:03:09 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_atoi(const char *nptr)
{
	char	*chaine;
	int		pos;
	int		res;

	chaine = (char *)nptr;
	pos = 1;
	res = 0;
	while ((*chaine >= 9 && *chaine <= 13) || *chaine == 32)
	{
		chaine++;
	}
	if (*chaine == '-')
		pos = -1;
	if (*chaine == '+' || *chaine == '-')
		chaine++;
	while (*chaine >= '0' && *chaine <= '9')
	{
		res = res * 10 + (*chaine - '0');
		chaine++;
	}
	return (res * pos);
}

int		ft_nbrlen(intmax_t nb, int base)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 0)
	{
		nb /= base;
		size++;
	}
	return (size);
}

int		ft_nbrlen_unsg(uintmax_t nb, int base)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(intmax_t value, char *base)
{
	char			*s;
	long long		n;
	int				i;
	uintmax_t		base2;

	base2 = ft_strlen(base);
	i = 1;
	n = value;
	while ((n /= base2) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		s[i] = (n % base2 < 10) ? n % base2 + '0' : n % base2 + 'a' - 10;
		n /= base2;
	}
	return (s);
}

char	*ft_itoa_base_uns(uintmax_t value, char *base)
{
	char					*str;
	unsigned long long int	n;
	int						len;
	int						tab;

	len = 1;
	tab = ft_strlen(base);
	n = value;
	if (tab < 2 || tab > 16)
		return (0);
	while ((n /= tab))
		len++;
	n = value;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[n % tab];
		len--;
		n = n / tab;
	}
	return (str);
}
