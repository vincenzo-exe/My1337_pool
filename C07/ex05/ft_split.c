#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && is_sep(str[i], charset) == 0)
				i++;
		}
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_sep(str[i], charset) == 0)
		i++;
	return (i);
}

char	*copy_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		j;

	words = word_count(str, charset);
	split = malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != '\0' && is_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			split[j] = copy_word(&str[i], word_len(&str[i], charset));
			j++;
			while (str[i] != '\0' && is_sep(str[i], charset) == 0)
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}