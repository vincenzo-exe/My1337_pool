#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_free_tab(t_stock_str *tab, int i)
{
	while (i >= 0)
	{
		free(tab[i].copy);
		i--;
	}
	free(tab);
}

int	ft_fill_tab(t_stock_str *tab, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)
		{
			ft_free_tab(tab, i);
			return (0);
		}
		i++;
	}
	return (1);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*output;

	output = malloc(sizeof(t_stock_str) * (ac + 1));
	if (output == NULL)
		return (NULL);
	if (ft_fill_tab(output, ac, av) == 0)
		return (NULL);
	output[ac].str = 0;
	output[ac].copy = 0;
	return (output);
}