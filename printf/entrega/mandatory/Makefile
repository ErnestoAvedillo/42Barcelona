# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:29:34 by eavedill          #+#    #+#              #
#    Updated: 2022/12/27 20:14:07 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf ft_utoa ft_addrtoa ft_printf_args

OBJS = $(addsuffix .o,$(SRC))

DEPS = $(addsuffix .d,$(SRC))

SRCS = $(addsuffix .c,$(SRC))

DIRLIBFT = ../libft/
LIBNAME = libft.a
LIBFT= $(addprefix $(DIRLIBFT),$(LIBNAME))

INCLUDE = ft_printf.h

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(LIBNAME) $(NAME)

-include $(INCLUDE))

$(NAME): $(OBJS) $(DEPS) $(LIBNAME)
	@cp -p $(LIBNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $*.c -o $*.o

%.d : %.c $(INCLUDE)
	$(CC) -MM $(FLAGS) -c $*.c > $*.d

$(LIBNAME): $(LIBFT)
	@cp -p $(LIBFT) $(LIBNAME)

$(LIBFT):
	@make -C$(DIRLIBFT) bonus

print:
	@echo $(INCLUDE)
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(NAME)
	@echo $(LIBFT)

clean:
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) $(HEAD_DEPS) $(HEAD_OBJS)
	make -C$(DIRLIBFT) clean

fclean:     clean
	@$(RM) $(NAME) $(LIBFT) $(LIBNAME)
	make -C$(DIRLIBFT) fclean

re:         fclean libft_make $(NAME) 

.PHONY: all re clean fclean re $(LIBFT) 
