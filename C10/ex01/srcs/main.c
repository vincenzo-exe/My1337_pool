#include "../includes/ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_cat(argv[i]);
		i++;
	}
	return (0);
}
