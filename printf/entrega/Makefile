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

NAME =  ft_printf.a

TEST = ../test.c

SRC = ft_printf

DIROBJ = ./obj/

DIRDEP = ./dep/

DIRSRC = ./entrega/

NAMLIB = $(addprefix $(DIRSRC),$(NAME))

SRCS = $(addprefix $(DIRSRC),$(addsuffix .o,$(SRC)))

OBJS = $(addprefix $(DIROBJ),$(addsuffix .o,$(SRC)))

DEPS = $(addprefix $(DIRDEP),$(addsuffix .p,$(SRC)))

INCLUDE= $(NAME:.a=.h)

FLAGINC = -I. -I./entrega/

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	ar -rcs $(NAMLIB) $(OBJS) $(DEPS)

$(DIROBJ)%.o: %.c
	$(CC) $(FLAGS) $(FLAGINC) -c $*.c -o $(DIROBJ)*.o

$(DIRDEP)%.d: %.c
	$(CC) $(FLAGS) $(FLAGINC) -MM -c $*.c > $(DIRDEP)*.d 


test: ../test.a
	$(CC) $(FLAGS)  -o $(TEST:.c=.a) $(TEST) $(NAMLIB) $(INCLUDE)

clean: 
	$(RM) $(OBJS) $(DEPS) 

fclean:
	clean $(NAME)

re:
	fclean $(NAME)

print: 
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(SRCS)
	@echo $(TEST)
	@echo $(INCLUDE)


.PHONY: all re clean fclean re