#include <stdlib.h>

int		check_base(char *base);
int		ft_atoi_base(char *nbr, char *base);
char	*ft_putnbr_base(int nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	number;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(number, base_to));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
