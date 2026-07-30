#include <stdlib.h>

int		ft_strlen(char *str);

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	value;

	i = 0;
	sign = 1;
	result = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	value = get_index(nbr[i], base);
	while (value != -1)
	{
		result = result * ft_strlen(base) + value;
		i++;
		value = get_index(nbr[i], base);
	}
	return (result * sign);
}

int	get_size(long nb, int len)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= len)
	{
		nb /= len;
		size++;
	}
	return (size);
}

void	fill_digits(char *str, long nb, char *base, int i)
{
	int	len;

	len = ft_strlen(base);
	if (nb == 0)
	{
		str[i] = base[0];
		return ;
	}
	while (nb > 0)
	{
		str[i--] = base[nb % len];
		nb /= len;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char *str;
	long nb;
	int size;

	nb = nbr;
	size = get_size(nb, ft_strlen(base));
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	fill_digits(str, nb, base, size - 1);
	return (str);
}