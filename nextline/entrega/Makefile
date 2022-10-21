# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 06:42:01 by eavedill          #+#    #+#              #
#    Updated: 2022/10/19 06:55:22 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line.a

SRC= get_next_line get_next_line_utils

OBJDTS = ./objdts/

SCRS =  $(addsuffix .c,(SRC))

OBJS =  $(addprefix, $(OBJDTS),$(addsuffix .o,(SRC)))

DSTS =  $(addprefix, $(OBJDTS),$(addsuffix .d,(SRC)))

INCLUDE = $(NAME:.a=.h)

FLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -rfd

AR = ar -rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

$(OBJDST)%.o: %.c
	$(CC) $(FLAGS) -o $(BOJDTS)$*.c -c $*.C

$(OBJDTS)%.d:%.c $(NCLUDE)
	$(CC) -MM $(FLAGS) $*.c > $(OBJDTS)$*.d

all: $(NAME)

print:
	@echo $(NAME)
	@echo $(OBJDTS)
	@echo $(OBJS)
	@echo $(DSTS)
	@echo $(SRCS)

clean:
	$(RM) $(OBJDTS)

fclean:
	clean $(NAME)

re:	fclean $(NAME)

.PHONY: all re fclean clean
