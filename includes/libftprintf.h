/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:36:54 by sebbaill          #+#    #+#             */
/*   Updated: 2021/08/18 18:10:41 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define CONVERSIONS	"cspdiouxX%"
# define FLAGS			"-. *0123456789"
# define VALID			"cspdiouxX%-. *0123456789"

# define MINUS			0
# define ZERO			1
# define DOT			2

# define HEXA_UPPER		"0123456789ABCDEF"
# define HEXA_LOWER		"0123456789abcdef"
# define DECIMAL		"0123456789"

typedef struct		s_data
{
	const char		*str;
	int				start;
	int				end;
	int				pos;
	int				f[3];
	int				width;
	int				precis;
	int				width_pad;
	int				precis_pad;
	unsigned int	return_val;
	va_list			ap;
}					t_data;

typedef struct		s_llist
{
	char			identifier;
	void			(*ptr_ft)(t_data *arg);
	struct s_llist	*next;
}					t_llist;

int					ft_printf(const char *format, ...);
int					ft_read_format(t_data *arg, t_llist *list_conv);
void				ft_parse(t_data *arg, t_llist *list_conv);
void				ft_width(t_data *arg);
void				ft_precision(t_data *arg);
void				ft_flags(t_data *arg);
void				ft_conversion(t_data *arg, t_llist *list_conv);
void				ft_printcar(t_data *arg);
void				ft_parse_conv(t_data *arg, int conv, int len);
void				ft_case1(t_data *arg, int conv, int len);
void				ft_case2(t_data *arg, int conv, int len);
void				ft_case3(t_data *arg, int len);
void				ft_case4(t_data *arg, int conv, int len);
void				ft_case5(t_data *arg, int len);
void				ft_convert_c(t_data *arg);
void				ft_convert_i(t_data *arg);
void				ft_convert_d(t_data *arg);
void				ft_convert_u(t_data *arg);
void				ft_convert_x(t_data *arg);
void				ft_convert_p(t_data *arg);
void				ft_convert_o(t_data *arg);
void				ft_convert_s(t_data *arg);
void				ft_write_blank(int n);
void				ft_write_zero(int n);
void				ft_write_pad(int pad, char *flag);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_atoi(const char *nptr);
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *str);
int					ft_nbrlen(intmax_t nb, int base);
int					ft_nbrlen_unsg(uintmax_t nb, int base);
char				*ft_itoa_base(intmax_t value, char *base);
char				*ft_itoa_base_uns(uintmax_t value, char *base);

#endif
