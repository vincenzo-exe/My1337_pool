#include "../includes/ft_hexdump.h"

void	print_error(char *file);
void	fill_offset(char *line, int offset);
void	fill_hex(char *line, unsigned char *buf, int len, int *j);
void	fill_ascii(char *line, unsigned char *buf, int len, int *j);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_hex(unsigned char *buf, int len, int offset)
{
	char	line[100];
	int		j;

	j = 8;
	fill_offset(line, offset);
	line[8] = ' ';
	fill_hex(line, buf, len, &j);
	line[j++] = '|';
	fill_ascii(line, buf, len, &j);
	line[j++] = '|';
	line[j++] = '\n';
	write(1, line, j);
}

void	ft_hexdump(char *file)
{
	int fd;
	int ret;
	int offset;
	unsigned char buffer[16];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error(file);
		return ;
	}
	offset = 0;
	ret = read(fd, buffer, 16);
	while (ret > 0)
	{
		print_hex(buffer, ret, offset);
		offset += ret;
		ret = read(fd, buffer, 16);
	}
	close(fd);
}