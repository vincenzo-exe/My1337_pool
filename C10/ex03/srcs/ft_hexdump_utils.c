#include "../includes/ft_hexdump.h"

int		ft_strlen(char *str);

void	print_error(char *file)
{
	write(2, "ft_hexdump: ", 12);
	write(2, basename(file), ft_strlen(basename(file)));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	fill_offset(char *line, int offset)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		line[i] = hex[offset % 16];
		offset /= 16;
		i--;
	}
}

void	fill_hex(char *line, unsigned char *buf, int len, int *j)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			line[(*j)++] = hex[buf[i] / 16];
			line[(*j)++] = hex[buf[i] % 16];
		}
		else
		{
			line[(*j)++] = ' ';
			line[(*j)++] = ' ';
		}
		if (i % 2)
			line[(*j)++] = ' ';
		i++;
	}
}

void	fill_ascii(char *line, unsigned char *buf, int len, int *j)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			line[(*j)++] = buf[i];
		else
			line[(*j)++] = '.';
		i++;
	}
}