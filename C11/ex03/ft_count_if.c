int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	if (tab == NULL || f == NULL || length <= 0)
		return (0);
	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
