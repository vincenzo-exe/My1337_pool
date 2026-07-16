#ifndef FT_TAIL_H
# define FT_TAIL_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

void	ft_tail(char *file, int size);

#endif