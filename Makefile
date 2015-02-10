CC =		clang++

RM =		rm -f

INCLUDES =	-Iheaders/

CFLAGS =	-Wall -Wextra -Wall

NAME =		bin/avm

SRC =		src/Int8.cpp \
		src/Int16.cpp \
		src/Int32.cpp \
		src/Float.cpp \
		src/Double.cpp

OBJ =		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean 
