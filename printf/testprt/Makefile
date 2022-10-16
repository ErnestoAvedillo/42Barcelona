# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:29:34 by eavedill          #+#    #+#              #
#    Updated: 2022/10/07 16:29:41 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  test_lib.a

SRC = standardprt specialtest

DIROBJ = ./obj/

DIRDEP = ./dep/


NAMLIB = $(NAME)

SRCS = $(addprefix $(DIRSRC),$(addsuffix .c,$(SRC)))

OBJS = $(addprefix $(DIROBJ),$(addsuffix .o,$(SRC)))

DEPS = $(addprefix $(DIRDEP),$(addsuffix .p,$(SRC)))

INCLUDE= $(NAME:.a=.h)

FLAGINC = -I.

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rfd

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS)

$(DIROBJ)%.o $(DIRDEP)%.d : %.c
	mkdir -p $(DIRDEP)
	mkdir -p $(DIROBJ)
	$(CC) $(FLAGS) $(FLAGINC) -c $*.c -o $(DIROBJ)$*.o
	$(CC) $(FLAGS) $(FLAGINC) -MM -c $*.c > $(DIRDEP)$*.d

clean: 
	$(RM) $(OBJS) $(DEPS) $(DIROBJ) $(DIRDEP)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

print: 
	@echo $(OBJS)
	@echo $(DIROBJ)
	@echo $(DEPS)
	@echo $(DIRDEP)
	@echo $(SRCS)
	@echo $(NAME)
	@echo $(INCLUDE)


.PHONY: all re clean fclean re print