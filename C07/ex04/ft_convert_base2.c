#include <stdlib.h>

int			ft_strlen(char *str);

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
	int	res;
	int	val;

	i = 0;
	sign = 1;
	res = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\v'
		|| nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	val = get_index(nbr[i], base);
	while (val != -1)
	{
		res = res * ft_strlen(base) + val;
		i++;
		val = get_index(nbr[i], base);
	}
	return (res * sign);
}

static int	get_size(long nb, int len)
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

static void	fill_digits(char *str, long nb, char *base, int i)
{
	int	len;

	len = ft_strlen(base);
	if (nb == 0)
		str[i] = base[0];
	while (nb > 0)
	{
		str[i--] = base[nb % len];
		nb /= len;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*str;
	long	nb;
	int		size;

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
