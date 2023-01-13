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
revrotate_moves rotate_moves sort_stack sort_stack_st2 sort_utils_1 sort_utils_2 check_duplicates\
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
RM := rm -rfd
CC := gcc
FLAG:= -Wall -Wextra -Werror

all:$(NAME)
	./$(NAME) 122 -681 657 45 427 139 -568 -606 -813 612 -718 726 119 430 700 -950 902 -571 30 748 -880 -633 -515 -720 695 -965 251 -787 501 586 -337 -503 330 209 -725 -999 328 -443 591 554 -233 675 -615 207 -244 -448 -13 978 884 792 -587 765 -66 231 -155 -133 81 320 128 -270 -731 0 -830 -708 -333 948 -2 899 438 572 -748 -630 -786 980 993 -816 603 -225 215 234 153 -417 -279 -242 -303 8 -196 -853 -860 -509 644 -288 -945 943 849 -576 -797 -559 747 -935 882 

win:$(NAME)
	./$(NAME).exe 122 -681 657 -417 -279 -242 -303 8 -196 -853 -860 -509 644 45 427 139 -568 -606 -813 612 -718 726 119 430 700 -950 902 -571 30 748 -880 -630 -786 980 993 -816 603 -225 215 234 153 -633 -515 -720 695 -965 251 -787 501 586 -337 -503 330 209 -725 -288 -945 943 849 -576 -797 -559 747 -935 882 -999 328 -443 591 554 -233 675 -615 207 -244 -448 -13 978 884 792 -587 765 -66 231 -155 -133 81 320 128 -270 -731 -830 -708 -333 948 -2 899 438 572 -748

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