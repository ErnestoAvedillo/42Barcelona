# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:42:29 by eavedill          #+#    #+#              #
#    Updated: 2022/10/29 11:42:44 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = testlib.a	

SRC= standard

OBJDTS = ./objdts/

SCRS =  $(addsuffix .c,$(SRC))
SCRS_BONUS =  $(addsuffix .c,$(SRC_BONUS))

OBJS =  $(addprefix $(OBJDTS),$(addsuffix .o,$(SRC)))
OBJS_BONUS =  $(addprefix $(OBJDTS),$(addsuffix .o,$(SRC_BONUS)))

DSTS =  $(addprefix $(OBJDTS),$(addsuffix .d,$(SRC)))
DSTS_BONUS =  $(addprefix $(OBJDTS),$(addsuffix .d,$(SRC_BONUS)))

INCLUDE = $(NAME:.a=.h)
INCLUDE_BONUS = $(NAME_BONUS:.a=.h)

FLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -rfd

AR = ar -rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

$(OBJDTS)%.o: %.c $(INCLUDE)
	mkdir -p $(OBJDTS)
	$(CC) $(FLAGS) -I.$(INCLUDE) -o $(OBJDTS)$*.o -c $*.c

$(OBJDTS)%.d:%.c $(INCLUDE) $(INCLUDE_BONUS)
	mkdir -p $(OBJDTS)
	$(CC) -MM $(FLAGS) $*.c > $(OBJDTS)$*.d

all: $(NAME)

bonus: $(NAME_BONUS)

print:
	@echo $(NAME)
	@echo $(OBJDTS)
	@echo $(OBJS)
	@echo $(DSTS)
	@echo $(SRCS)

clean:
	$(RM) $(OBJDTS)

fclean:	clean 
	$(RM) $(NAME) $(NAME_BONUS)

re:	fclean $(NAME)

.PHONY: all re fclean clean
