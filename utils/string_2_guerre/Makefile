NAME	= Megaphone
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
SRC		= ./String_2_guerre.cpp ./test.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		 $(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean
