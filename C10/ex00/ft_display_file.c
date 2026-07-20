#include <fcntl.h>
#include <unistd.h>

void	display_file(int fd)
{
	int		bytes;
	char	buffer[1024];

	bytes = read(fd, buffer, sizeof(buffer));
	while (bytes > 0)
	{
		write(1, buffer, bytes);
		bytes = read(fd, buffer, sizeof(buffer));
	}
}

int	main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	display_file(fd);
	close(fd);
	return (0);
}