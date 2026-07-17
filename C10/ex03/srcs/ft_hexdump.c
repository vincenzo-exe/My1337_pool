#include "../includes/ft_hexdump.h"

int     ft_strlen(char *str)
{
        int i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

void    print_error(char *file)
{
        write(2, "ft_hexdump: ", 12);
        write(2, basename(file), ft_strlen(basename(file)));
        write(2, ": ", 2);
        write(2, strerror(errno), ft_strlen(strerror(errno)));
        write(2, "\n", 1);
}

void    print_hex(unsigned char *buf, int len, int offset)
{
        char    hex[] = "0123456789abcdef";
        char    line[100];
        int     i;
        int     j;

        j = 8;

        i = 7;
        while (i >= 0)
        {
                line[i] = hex[offset % 16];
                offset /= 16;
                i--;
        }

        line[j++] = ' ';

        i = 0;
        while (i < 16)
        {
                if (i < len)
                {
                        line[j++] = hex[buf[i] / 16];
                        line[j++] = hex[buf[i] % 16];
                }
                else
                {
                        line[j++] = ' ';
                        line[j++] = ' ';
                }

                if (i % 2)
                        line[j++] = ' ';
                i++;
        }

        line[j++] = '|';

        i = 0;
        while (i < len)
        {
                if (buf[i] >= 32 && buf[i] <= 126)
                        line[j++] = buf[i];
                else
                        line[j++] = '.';
                i++;
        }

        line[j++] = '|';
        line[j++] = '\n';

        write(1, line, j);
}

void    ft_hexdump(char *file)
{
        int             fd;
        int             ret;
        int             offset;
        unsigned char   buffer[16];

        fd = open(file, O_RDONLY);

        if (fd == -1)
        {
                print_error(file);
                return ;
        }

        offset = 0;

        while ((ret = read(fd, buffer, 16)) > 0)
        {
                print_hex(buffer, ret, offset);
                offset += ret;
        }

        close(fd);
}