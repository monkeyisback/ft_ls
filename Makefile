NAME = ft_ls

SRCS = main.c

SRCO = main.o

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)

all: $(NAME)
	gcc -o $(NAME) $(SRCO)

clean:
	/bin/rm -f $(SRCO)

fclean:
	/bin/rm -f $(NAME)

re: fclean all