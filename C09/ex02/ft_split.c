#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !is_separator(str[i], charset))
			i++;
	}
	return (count);
}

int	word_length(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_separator(str[i], charset))
		i++;
	return (i);
}

char	*copy_word(char *str, int length)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char **result;
	int i;
	int j;

	result = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			result[j] = copy_word(&str[i], word_length(&str[i], charset));
			j++;
		}
		while (str[i] != '\0' && !is_separator(str[i], charset))
			i++;
	}
	result[j] = NULL;
	return (result);
}