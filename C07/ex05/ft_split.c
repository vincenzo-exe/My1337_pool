#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	return (i);
}

char	*copy_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
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
	char **split;
	int i;
	int j;

	split = malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			split[j] = copy_word(&str[i], word_len(&str[i], charset));
			j++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}