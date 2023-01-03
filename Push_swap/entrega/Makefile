# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 17:45:27 by eavedill          #+#    #+#              #
#    Updated: 2022/12/29 17:45:31 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#push-swap project
NAME := push_swap

SRC := push_swap check_errors create_stacks push_free push_utils sort_stack
DIR_SRC := ./srcs/
SRCS := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
DIR_OBJ := ./obj/
OBJS := $(addprefix $(DIR_OBJ),$(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(DIR_OBJ),$(addsuffix .d,$(SRC)))
INCLUDE = $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))

#libraries
DIR_LIBFT := ./libft/
NAME_LIBFT := libft.a
LIBFT_LIB := $(addprefix $(DIR_LIBFT),$(NAME_LIBFT))
DIR_PRINTF := ./printf/
NAME_PRINTF := libftprintf.a
PRINTF_LIB := $(addprefix $(DIR_PRINTF),$(NAME_PRINTF))



#instruciont for execution
RM := re -rfd
CC := gcc
FLAG:= -Wall -Wextra -Werror

all:$(NAME)
	./$(NAME) 1 2 3 4
-include: (DSTS)

$(NAME): $(DSTS) $(OBJS) $(NAME_PRINTF)
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(NAME_PRINTF)

$(DIR_OBJ)%.o $(DIR_OBJ)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $(DIR_SRC)$*.c -o $(DIR_OBJ)$*.o
	$(CC) -MM $(CFLAGS) -c $(DIR_SRC)$*.c > $(DIR_OBJ)$*.d

$(NAME_PRINTF):$(PRINTF_LIB)
	@cp -p $(PRINTF_LIB) $(NAME_PRINTF)

$(PRINTF_LIB):
	make -C$(DIR_PRINTF) all


clean:
	make -C$(DIR_PRINTF) clean
	$(RM) $(DIR_OBJ)

fclean: clean
	make -C$(DIR_PRINTF) fclean
	$(RM) $(NAME)

re: fclean all


print: 
	@echo SRCS:$(SRCS)
	@echo OBJS:$(OBJS)
	@echo DSTS:$(DSTS)
	@echo PRINTF_LIB:$(PRINTF_LIB)
	@echo LIBFT_LIB:$(LIBFT_LIB)
	@echo LIBFT_LIB:$(DIR_OBJ)
	@echo $(DIR_OBJ)$%.d


.PHONY: print all re clean fclean $(PRINTF_LIB)