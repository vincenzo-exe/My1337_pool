#include "../includes/ft_tail.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_error(char *file)
{
	write(2, "ft_tail: ", 9);
	write(2, basename(file), ft_strlen(basename(file)));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

char	*read_file(int fd, int *len)
{
	char	*buffer;
	int		ret;

	buffer = malloc(100000);
	if (buffer == NULL)
		return (NULL);
	*len = 0;
	ret = read(fd, buffer + *len, 1);
	while (ret > 0)
	{
		(*len)++;
		ret = read(fd, buffer + *len, 1);
	}
	return (buffer);
}

void	ft_tail(char *file, int size)
{
	int fd;
	int len;
	char *buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error(file);
		return ;
	}
	buffer = read_file(fd, &len);
	if (buffer == NULL)
	{
		close(fd);
		return ;
	}
	if (len > size)
		write(1, buffer + len - size, size);
	else
		write(1, buffer, len);
	free(buffer);
	close(fd);
}