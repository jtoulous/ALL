NAME = pipex

CC = clang

LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c path_finder.c toolbox.c

OBJ = ${SRC:.c=.o}

all: $(LIBFT_NAME) $(NAME)

.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	 ${CC} $(OBJ) $(LIBFT_NAME) -o ${NAME}

$(LIBFT_NAME): 
	make -C $(LIBFT_PATH)

clean: 
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)
	
re: fclean all

.PHONY:
	re all clean fclean
