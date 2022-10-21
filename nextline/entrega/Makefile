# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 06:42:01 by eavedill          #+#    #+#              #
#    Updated: 2022/10/21 17:24:32 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line.a

SRC= get_next_line get_next_line_utils

OBJDTS = ./objdts/

SCRS =  $(addsuffix .c,$(SRC))

OBJS =  $(addprefix $(OBJDTS),$(addsuffix .o,$(SRC)))

DSTS =  $(addprefix $(OBJDTS),$(addsuffix .d,$(SRC)))

INCLUDE = $(NAME:.a=.h)

FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1000

CC = gcc

RM = rm -rfd

AR = ar -rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

$(OBJDTS)%.o: %.c
	mkdir -p $(OBJDTS)
	$(CC) $(FLAGS) -o $(OBJDTS)$*.o -c $*.c

$(OBJDTS)%.d:%.c $(NCLUDE)
	mkdir -p $(OBJDTS)
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
