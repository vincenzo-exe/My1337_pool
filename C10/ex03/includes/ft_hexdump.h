#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

void    ft_hexdump(char *file);

#endif