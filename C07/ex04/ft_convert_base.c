#include <stdlib.h>

int		check_base(char *base);
int		ft_atoi_base(char *nbr, char *base);
char	*ft_putnbr_base(int nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	number;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(number, base_to));
}