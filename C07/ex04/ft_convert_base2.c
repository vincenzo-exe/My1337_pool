#include <stdlib.h>

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
		if (base[i] == '+' || base[i] == '-' 
			|| base[i] == ' ')
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
	while (nbr[i])
	{
		value = get_index(nbr[i], base);
		if (value == -1)
			break ;
		result = result * ft_strlen(base) + value;
		i++;
	}
	return (result * sign);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*str;
	long	nb;
	int		len;
	int		i;
	int		size;

	nb = nbr;
	len = ft_strlen(base);
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
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	nb = nbr;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	i = size - 1;
	if (nb == 0)
		str[i] = base[0];
	while (nb > 0)
	{
		str[i] = base[nb % len];
		nb /= len;
		i--;
	}
	return (str);
}