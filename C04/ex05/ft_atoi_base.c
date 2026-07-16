int    get_index(char c, char *base)
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

int    ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i])
        i++;
    return (i);
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