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

SRC := push_swap check_errors create_stacks push_free push_moves push_utils \
revrotate_moves rotate_moves sort_stack sort_stack_st2 sort_utils_1 sort_utils_2 \
swap_moves
		 
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
	./$(NAME) -892 -962 -3 -651 -32 487 -191 330 -59 647 -684 244 631 -912 848 60 322 -650 445 103 -436 -591 -119 -473 -416 379 -540 941 -268 560 692 745 -47 -575 -247 -617 -847 -895 454 994 602 845 -545 -841 -320 -906 975 70 -214 378 938 84 20 -568 -823 12 -51 131 279 -291 840 -405 -932 -569 -980 -587 -959 -159 928 -739 -756 -871 -272 308 382 -113 -825 389 859 857 -368 -437 953 679 -780 535 370 305 744 725 427 -446 97 755 -747 -987 862 317 668 443

win:$(NAME)
	./$(NAME).exe -892 -462 -3 -651 -32 487 -191 330 -59 647 -684 244 631 -912 848 60 322 -650 445 103 -436 -591 -119 -473 -416 379 -540 941 -268 560 692 745 -47 -575 -247 -617 -847 -895 454 994 602 845 -545 -841 -320 -906 975 70 -214 378 938 84 20 -568 -823 12 -51 131 279 -291 840 -405 -932 -569 -980 -587 -959 -159 928 -739 -756 -871 -272 308 382 -113 -825 389 859 857 -368 -437 953 679 -780 535 370 305 744 725 427 -446 97 755 -747 -987 862 317 668 443

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