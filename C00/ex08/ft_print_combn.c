#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	generate_comb(int *tab, int n, int pos, int start)
{
	int	i;

	if (pos == n)
	{
		print_comb(tab, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		tab[pos] = i;
		generate_comb(tab, n, pos + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int tab[10];

	generate_comb(tab, n, 0, 0);
	write(1, "\n", 1);
}