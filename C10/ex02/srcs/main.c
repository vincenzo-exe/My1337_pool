#include "../includes/ft_tail.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	if (argc == 4 && strcmp(argv[1], "-c") == 0)
	{
		ft_tail(argv[3], ft_atoi(argv[2]));
	}
	return (0);
}