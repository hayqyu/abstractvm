CC =		g++

RM =		rm -f

CFLAGS =	-Wall -Wextra -Wall

NAME =		bin/avm

SRC =		src/IOperand.cpp

OBJ =		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean 
