#include "operations.h"
#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		get_operation(char op);
int		check_error(int index, int b);

int	main(int argc, char **argv)
{
	int (*functions[5])(int, int);
	int a;
	int b;
	int index;

	if (argc != 4)
		return (0);
	functions[0] = add;
	functions[1] = sub;
	functions[2] = mul;
	functions[3] = div;
	functions[4] = mod;
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	index = get_operation(argv[2][0]);
	if (index == -1 || check_error(index, b))
	{
		if (index == -1)
			ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	ft_putnbr(functions[index](a, b));
	write(1, "\n", 1);
	return (0);
}