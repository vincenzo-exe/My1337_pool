int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}
