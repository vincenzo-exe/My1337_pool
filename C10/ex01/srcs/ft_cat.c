#include "../includes/ft_cat.h"

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

void	print_error(char *file)
{
	write(2, "ft_cat: ", 8);
	write(2, basename(file), ft_strlen(basename(file)));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	ft_cat(char *file)
{
	int		fd;
	int		ret;
	char	buffer[1024];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error(file);
		return ;
	}
	ret = read(fd, buffer, sizeof(buffer));
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
}
