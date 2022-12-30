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

SRC := push_swap check_errors
DIR_SRC := ./srcs/
SRCS := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
DIR_OBJ := $(addprefix $(DIR_SRC),obj/)
OBJS := $(addprefix $(DIR_OBJ),$(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(DIR_OBJ),$(addsuffix .d,$(SRC)))

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




clean:

fclean: clean

re: fclean all

print: 
	@echo SRCS:$(SRCS)
	@echo OBJS:$(OBJS)
	@echo DSTS:$(DSTS)
	@echo PRINTF_LIB:$(PRINTF_LIB)
	@echo LIBFT_LIB:$(LIBFT_LIB)


.PHONY: print