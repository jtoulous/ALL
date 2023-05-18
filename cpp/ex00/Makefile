NAME	= megaphone
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98 -o

SRC		= ./megaphone.cpp

OBJ		= $(SRC:.c= .o)

all: $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		 $(CC) $(OBJ) $(CFLAGS) $(NAME)

clean:
		rm -rf $(OBJ)

fclean:
		clean
		rm -rf $(NAME)

re: fclean all

.PHONY:
		re all fclean clean