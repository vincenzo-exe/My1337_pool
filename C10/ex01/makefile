NAME = ft_cat

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c srcs/ft_cat.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)