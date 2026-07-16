#include <stdlib.h>
#include "ft_stock_str.h"

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

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*output;
	int			i;

	output = malloc(sizeof(t_stock_str) * (ac + 1));
	if (output == NULL)
		return (NULL);

	i = 0;
	while (i < ac)
	{
		output[i].size = ft_strlen(av[i]);
		output[i].str = av[i];
		output[i].copy = ft_strdup(av[i]);

		if (output[i].copy == NULL)
		{
			while (i >= 0)
			{
				free(output[i].copy);
				i--;
			}
			free(output);
			return (NULL);
		}
		i++;
	}

	output[i].str = NULL;
	output[i].copy = NULL;

	return (output);
}