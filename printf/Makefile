# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/10/12 16:26:07 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = test

INCLUDE = test.h

#Datos de la libreria 1
LIB = libft.a
DIRLIBS = ../Libft/entrega/
LIBS = $(addprefix $(DIRLIBS), $(LIB))

#Datos de la libreria 2 (en mi caso los tests.
LIB_PRT = printf.a
DIRLIB_PRT = ./entrega/
LIBS_PRT = $(addprefix $(DIRLIB_TEST), $(LIB_TEST))

#Datos de la libreria 2 (en mi caso los tests.
LIB_TEST = test.a
DIRLIB_TEST = ./test/
LIBS_TEST = $(addprefix $(DIRLIB_TEST), $(LIB_TEST))


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

CC = gcc

RM = rm -rfd

CFLAGS = -Wall -Wextra -Werror -I.

NAME = $(addsuffix .a, $(SRC))

#tienen que estar en este orden de llamada. 
# la segunda llama a la primera , la tercera a la segunda y así sucesivamente
all: $(LIBS) $(LIBS_TEST) $(NAME)

$(NAME): $(OBJS) $(INCLUDE) $(LIBS) $(LIBS_TEST)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS_TEST) $(LIBS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $*.c -o $*.o

#To generate the  libft.a
$(LIBS):
	$(MAKE) -C$(DIRLIBS) bonus

#To generate the libft_tesst.a (in my case for the test library)
$(LIBS_TEST):
	$(MAKE) -C$(DIRLIB_TEST) all

subdirs: $(DIRLIBS) $(DIRLIB_TEST)

clean:		
	$(RM) $(OBJS) 
	$(MAKE) -C$(DIRLIB_TEST) clean 
	$(MAKE) -C$(DIRLIBS) clean
	$(MAKE) -C$(DIRLIB_PRT) clean

fclean:		clean
	$(RM) $(NAME) 
	$(MAKE) -C$(DIRLIB_TEST) fclean 
	$(MAKE) -C$(DIRLIBS) fclean
	$(MAKE) -C$(DIRLIB_PRT) fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re $(LIBS) $(LIBS_TEST)
