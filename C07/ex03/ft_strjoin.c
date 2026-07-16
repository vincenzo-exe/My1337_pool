#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		totalsize;
	int		i;

	if (size == 0)
	{
		strjoin = malloc(sizeof(char));
		if (strjoin == NULL)
		{
			return (NULL);
		}
		strjoin[0] = '\0';
		return (strjoin);
	}
	totalsize = 0;
	i = 0;
	while (i < size)
	{
		totalsize += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			totalsize += ft_strlen(sep);
		}
		i++;
	}
	strjoin = malloc(totalsize + 1);
	if (strjoin == NULL)
	{
		return (NULL);
	}
	strjoin[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(strjoin, strs[i]);
		if (i < size - 1)
		{
			ft_strcat(strjoin, sep);
		}
		i++;
	}
	return (strjoin);
}