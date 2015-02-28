##
## Makefile for abstractvm in /home/gazzol_j/rendu/abstractvm
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Tue Feb 10 16:03:27 2015 julien gazzola
## Last update Sat Feb 28 08:50:40 2015 Cédric Voinnet
##

CC =		g++

RM =		rm -f

INCLUDES =	-Iheaders/

CXXFLAGS =	-Wall -Wextra -Wall -g3

NAME =		bin/avm

SRC =		src/Error.cpp \
		src/main.cpp \
		src/Command.cpp \
		src/Operand.cpp \
		src/Calc.cpp

OBJ =		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:		%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean 
