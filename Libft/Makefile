# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/10/10 10:19:23 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = test

INCLUDE = test.h

#Datos de la libreria 1
LIB = libft.a
DIRLIBS = ./entrega/
LIBS = $(addprefix $(DIRLIBS), $(LIB))

#Datos de la libreria 2 (en mi caso los tests.
LIB_TEST = test_lib.a
DIRLIB_TEST = ./test_lib/
LIBS_TEST = $(addprefix $(DIRLIB_TEST), $(LIB_TEST))


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = $(addsuffix .a, $(SRC))

#tienen que estar en este orden de llamada. 
# la segunda llama a la primera , la tercera a la segunda y así sucesivamente
all: $(LIBS) $(LIBS_TEST) $(NAME)

$(NAME): $(OBJS) $(INCLUDE) $(LIBS) $(LIBS_TEST)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS_TEST) $(LIBS)

%.o: %.c
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

fclean:		clean
	$(RM) $(NAME) 
	$(MAKE) -C$(DIRLIB_TEST) fclean 
	$(MAKE) -C$(DIRLIBS) fclean

re:			fclean $(NAME)

print:
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

.PHONY:		all clean fclean re $(LIBS) $(LIBS_TEST)
