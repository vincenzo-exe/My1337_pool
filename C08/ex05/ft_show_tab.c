#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb >= 10)
    {
		ft_putnbr(nb / 10);
    }
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);

		ft_putnbr(par[i].size);
		write(1, "\n", 1);

		ft_putstr(par[i].copy);
		write(1, "\n", 1);

		i++;
	}
}