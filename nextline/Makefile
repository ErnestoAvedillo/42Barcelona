# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 21:36:39 by eavedill          #+#    #+#              #
#    Updated: 2022/10/18 22:02:12 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = test.a

SRC = test

OBJDST = ./objdst/

SRCS = $(addsuffix .c,$(SRC))

OBJS = $(addprefix $(OBJDST),$(addsuffix .o,$(SRC)))

DSTS = $(addprefix $(OBJDST),$(addsuffix .d,$(SRC)))

FLAGS = -Wall -Werror -Wextra -I.
BUFFERFLAG = -D BUFFER_SIZE = 42

CC = gcc

RM = rm -rfd

$(NAME):  $(OBJS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) 

$(OBJDST)%.o: $(SRCS) $(DSTS)
	mkdir -p $(OBJDST)
	$(CC) $(FLAGS) -c $*.c -o $(OBJDST)$*.o

$(OBJDST)%.d: $(SRCS) $(INCLUDE)
	mkdir -p $(OBJDST)
	$(CC) -MM $(FLAGS) $(BUFFER_SIZE) -c $*.c > $(OBJDST)$*.d

all: $(NAME)

print:
	@echo $(OBJDST)
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DSTS)
	@echo $(NAME)

clean:
	$(RM) $(SRCS) $(DSTS) $(OBJSDSTS)

fclan:
	clean $(NAME)

re:	fclean $(NAME)

.PHONY: all re fclean clean 
