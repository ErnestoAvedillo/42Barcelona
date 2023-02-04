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

NAME_BNS := checker

SRC_COMMON := check_errors create_stacks push_free push_moves push_utils \
revrotate_moves rotate_moves check_duplicates swap_moves input_data \
check_stacks_status

SRC_M := $(SRC_COMMON) sort_stack_st3 sort_utils_1 sort_utils_2 basic_input \
		basic_5_input next_move move2top

SRC_B := $(SRC_COMMON) input_moves 

#Mandatory	 
DIR_SRC := ./srcs/
SRC_MND := $(NAME) $(SRC_M)
SRCS_MND := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC_MND)))
DIR_OBJ := ./obj/
OBJS := $(addprefix $(DIR_OBJ),$(addsuffix .o,$(SRC_MND)))
DSTS := $(addprefix $(DIR_OBJ),$(addsuffix .d,$(SRC_MND)))
INCLUDE = $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))
#Bonus
SRC_BNS := $(NAME_BNS) $(SRC_B)
SRCS_BNS := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC_BNS)))
OBJS_BNS := $(addprefix $(DIR_OBJ),$(addsuffix .o,$(SRC_BNS)))
DSTS_BNS := $(addprefix $(DIR_OBJ),$(addsuffix .d,$(SRC_BNS)))
INCLUDE_BNS = $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME_BNS)))
#libraries
#libft
DIR_LIBFT := ./libft/
NAME_LIBFT := libft.a
LIBFT_LIB := $(addprefix $(DIR_LIBFT),$(NAME_LIBFT))
#printf
DIR_PRINTF := ./printf/
NAME_PRINTF := libftprintf.a
PRINTF_LIB := $(addprefix $(DIR_PRINTF),$(NAME_PRINTF))
#nexline
DIR_NXLN := ./nextline/
NAME_NXLN := get_next_line.a
NXLN_LIB := $(addprefix $(DIR_NXLN),$(NAME_NXLN))



#instruciont for execution
RM := rm -rfd
CC := gcc
FLAG:= -Wall -Wextra -Werror

ARG := "-607 321 262 229 572 731 -463 653 722 553 11 -654 -476 233 -173 -553 848 226 577 -77 493 -228 -498 -891 -38 -759 -512 -45 955 716 275 786 -977 -334 -960 982 -801 692 -372 -852 -409 854 -328 882 -5 -423 -122 117 276 -704 -789 823 -480 979 134 -573 -867 -165 -667 174 309 293 -827 509 347 88 501 169 -149 798 -608 -227 408 550 -243 -94 -171 862 -312 602 -926 694 759 -963 344 -180 2 50 -427 -109 -986 797 660 880 -748 473 -644 -510 664 -649"
all:$(NAME)
	./$(NAME) $(ARG)
	./$(NAME) $(ARG) | wc -l
	./$(NAME) $(ARG) | ./checker_OS $(ARG)

win:$(NAME)
	./$(NAME).exe ""
	./$(NAME).exe 122 -681 657 -417 -279 -242 -303 8 -196 -853 -860 -509 644 45 427 139 -568 -606 -813 612 -718 726 119 430 700 -950 902 -571 30 748 -880 -630 -786 980 993 -816 603 -225 215 234 153 -633 -515 -720 695 -965 251 -787 501 586 -337 -503 330 209 -725 -288 -945 943 849 -576 -797 -559 747 -935 882 -999 328 -443 591 554 -233 675 -615 207 -244 -448 -13 978 884 792 -587 765 -66 231 -155 -133 81 320 128 -270 -731 -830 -708 -333 948 -2 899 438 572 -748

-include: (DSTS)

$(NAME): $(DSTS) $(OBJS) $(NAME_PRINTF)
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(NAME_PRINTF) 

$(DIR_OBJ)%.o $(DIR_OBJ)%.d: $(DIR_SRC)%.c $(INCLUDE) $(INCLUDE_BNS)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $(DIR_SRC)$*.c -o $(DIR_OBJ)$*.o
	$(CC) -MM $(CFLAGS) -c $(DIR_SRC)$*.c > $(DIR_OBJ)$*.d

$(NAME_PRINTF):$(PRINTF_LIB)
	@cp -p $(PRINTF_LIB) $(NAME_PRINTF)

$(PRINTF_LIB):
	make -C$(DIR_PRINTF) all

ARGS := "122 -681 657 45 427 139 -568 -606 -813 612 -718 726 119 430 700 -950 902 -571 30 748 -880 -633 -515 -720 695 -965 251 -787 501 586 -337 -503 330 209 -725 -999 328 -443 591 554 -233 675 -615 207 -244 -448 -13 978 884 792 -587 765 -66 231 -155 -133 81 320 128 -270 -731 0 -830 -708 -333 948 -2 899 438 572 -748 -630 -786 980 993 -816 603 -225 215 234 153 -417 -279 -242 -303 8 -196 -853 -860 -509 644 -288 -945 943 849 -576 -797 -559 747 -935 882"
bonus: $(NAME_BNS)
	./$(NAME) $(ARGS) | wc -l
#	./$(NAME) $(ARGS)
	./$(NAME) $(ARGS) | ./$(NAME_BNS) $(ARGS)
#	./$(NAME_BNS) $(ARGS)

$(NAME_BNS): $(DSTS_BNS) $(OBJS_BNS) $(NAME_PRINTF) $(NAME_NXLN)
	$(CC) $(FLAG) -o $(NAME_BNS) $(OBJS_BNS) $(NAME_NXLN) $(NAME_PRINTF)

$(NAME_NXLN):$(NXLN_LIB)
	@cp -p $(NXLN_LIB) $(NAME_NXLN)

$(NXLN_LIB):
	make -C$(DIR_NXLN) all

clean:
	make -C$(DIR_PRINTF) clean
	make -C$(DIR_NXLN) clean
	$(RM) $(DIR_OBJ)

fclean: clean
	make -C$(DIR_NXLN) clean
	make -C$(DIR_PRINTF) fclean
	$(RM) $(NAME) $(NAME_NXLN) $(NAME_BNS) $(NAME_PRINTF)

re: fclean all


print: 
	@echo NAME_BNS:$(NAME_BNS)
	@echo NAME:$(NAME)
	@echo SRCS_MND:$(SRCS_MND)
	@echo SRCS_BNS:$(SRCS_BNS)
	@echo OBJS:$(OBJS)
	@echo DSTS:$(DSTS)
	@echo PRINTF_LIB:$(PRINTF_LIB)
	@echo LIBFT_LIB:$(LIBFT_LIB)
	@echo LIBFT_LIB:$(DIR_OBJ)
	@echo $(DIR_OBJ)$%.d


.PHONY: print all re clean fclean bonus $(PRINTF_LIB) $(NXLN_LIB)