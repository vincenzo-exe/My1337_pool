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


void	ft_tail(char *file, int size)
{
	int		fd;
	int		len;
	int		ret;
	char	*buffer;

	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		print_error(file);
		return ;
	}

	buffer = malloc(100000);

	if (buffer == NULL)
	{
		close(fd);
		return ;
	}

	len = 0;

	while ((ret = read(fd, buffer + len, 1)) > 0)
		len++;

	if (len > size)
		write(1, buffer + len - size, size);
	else
		write(1, buffer, len);

	free(buffer);
	close(fd);
}