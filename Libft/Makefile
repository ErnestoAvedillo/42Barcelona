# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill   
#    Updated: 2022/09/24 16:03:08 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.a

SRC = $(NAME:.a=.c)

NAME_LIBFT = ./entrega/libft.a

NAME_LIB_TESTS = ./test_lib/test_lib.a

LIBS = -I./test_lib -I./entrega

all: $(NAME)

comp_lib:$(NAME_LIBFT)

comp_test:$(NAME_LIB_TESTS)

$(NAME):test.c $(NAME_LIBFT) $(NAME_LIB_TESTS)
	gcc -Wall -Werror -Wextra $(LIBS) -o $(NAME) $(SRC) $(NAME_LIB_TESTS) $(NAME_LIB_TESTS:.a=.h) $(NAME_LIBFT) $(NAME_LIBFT:.a=.h)

$(NAME_LIBFT):
	make -Centrega all

$(NAME_LIB_TESTS):
	make -Ctest_lib all

fclean:
	make -Centrega fclean
	make -Ctest_lib fclean
	rm $(NAME)
