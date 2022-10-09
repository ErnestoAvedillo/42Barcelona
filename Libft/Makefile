# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/09/24 16:03:27 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = test

INCLUDE = test.h

LIB = libft.a
DIRLIBS = ./entrega/
LIBS = $(addprefix $(DIRLIBS), $(LIB))

LIB_TEST = test_lib.a
DIRLIB_TEST = ./test_lib/
LIBS_TEST = $(addprefix $(DIRLIB_TEST), $(LIB_TEST))

subdirs = $(DIRLIB_TEST) $(DIRLIBS)

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = $(addsuffix .a, $(SRC))

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(addprefix $(DIRLIB_TEST), $(LIB_TEST)) $(addprefix $(DIRLIBS), $(LIB))

%.o: %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

$(SUBDIRS):
	$(MAKE) -C $@
#$(LIB): $(LIBS)
#	$(MAKE) -C$(DIRLIBS) bonus
#
#$(LIB_TEST): $(LIBS_TEST)
#	$(MAKE) -C$(DIRLIB_TEST) all

clean:		
	$(RM) $(OBJS) 

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

print:
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

.PHONY:		all clean fclean re subdirs $(SUBDIRS)
