NAME	= Bureaucratz
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
SRC		= ./main.cpp ./Bureaucrat.cpp ./Form.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp ./ShrubberyCreationForm.cpp ./Intern.cpp
	
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