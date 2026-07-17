#include "../includes/ft_hexdump.h"

int     main(int argc, char **argv)
{
        if (argc == 3 && strcmp(argv[1], "-C") == 0)
                ft_hexdump(argv[2]);
        return (0);
}