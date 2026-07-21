int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	if (length <= 1)
		return (1);
	ascending = 1;
	descending = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			descending = 0;
		else if (f(tab[i], tab[i + 1]) > 0)
			ascending = 0;
		i++;
	}
	return (ascending || descending);
}
