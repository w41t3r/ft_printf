#include "includes/libftprintf.h"

int		main(void)
{
	char	*str = "Salut tous le monde";
	ft_printf("test print char: %c\n", 'A');
	ft_printf("test print str: %s\n", str);
	ft_printf("test print ptr: %p\n", str);
	return (0);
}
