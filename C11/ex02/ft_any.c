int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	if (tab == NULL || f == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
