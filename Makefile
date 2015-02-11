##
## Makefile for abstractvm in /home/gazzol_j/rendu/abstractvm
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Tue Feb 10 16:03:27 2015 julien gazzola
## Last update Wed Feb 11 15:07:18 2015 Cédric Voinnet
##

CC =		clang++

RM =		rm -f

INCLUDES =	-Iheaders/

CFLAGS =	-Wall -Wextra -Wall -g3

NAME =		bin/avm

SRC =		src/main.cpp \
		src/Command.cpp \
		src/Operand.cpp \
		src/Float.cpp \
		src/Double.cpp \
		src/Int8.cpp \
		src/Int16.cpp \
		src/Int32.cpp 

OBJ =		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:		%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean 
