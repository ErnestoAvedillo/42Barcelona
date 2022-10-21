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

#dato sobre la libreria
NAMELIB = get_next_line
DIRLIB = ./entrega/
NAMELIBS = $(addprefix $(DIRLIB),$(addsuffix .a,$(NAMELIB)))


FLAGS = -Wall -Werror -Wextra -I.
BUFFERFLAG = -D BUFFER_SIZE = 42

CC = gcc

RM = rm -rfd

$(NAME):  $(OBJS) $(NAMELIBS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(NAMELIBS)

$(OBJDST)%.o: $(SRCS) $(DSTS)
	mkdir -p $(OBJDST)
	$(CC) $(FLAGS) -c $*.c -o $(OBJDST)$*.o

$(OBJDST)%.d: $(SRCS) $(INCLUDE)
	mkdir -p $(OBJDST)
	$(CC) -MM $(FLAGS) $(BUFFER_SIZE) -c $*.c > $(OBJDST)$*.d

all: $(NAME)

$(NAMELIBS):
	make -C$(DIRLIB) all

print:
	@echo $(OBJDST)
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DSTS)
	@echo $(NAME)
	@echo $(NAMELIBS)

clean:
	$(RM) $(OBJS) $(DSTS) $(OBJDST) 

fclean:	clean 
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all re fclean clean $(NAMELIBS)
