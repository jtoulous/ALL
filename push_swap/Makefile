NAME = push_swap

SRC = book_of_knowledge.c broute_force.c errorz_and_remaster.c push_swap.c possibilityz_1.c possibilityz_2.c possibilityz_3.c push.c radix.c rev_rotate.c rotate.c swap.c toolbox.c toolbox2.c toolbox3.c errorz_and_remaster_2.c toolbox4.c

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)
	
$(NAME): 
	clang $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(SRC:.c=.o)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re bonus
