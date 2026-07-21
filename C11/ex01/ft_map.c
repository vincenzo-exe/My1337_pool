int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	i;

	if (tab == NULL || f == NULL || length <= 0)
		return (NULL);
	new_tab = malloc(sizeof(int) * length);
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}
