# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:29:34 by eavedill          #+#    #+#              #
#    Updated: 2022/11/25 14:35:24 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf ft_utoa ft_addrtoa ft_printf_args bonus fill_list fill_list_utils \
		bonus_utils print_format write_extended ft_print_suf ft_print_chrs check_utils

OBJS = $(addsuffix .o,$(SRC))

DEPS = $(addsuffix .d,$(SRC))

SRCS = $(addsuffix .c,$(SRC))

DIRLIBFT = ./libft/
LIBNAME = libft.a
LIBFT= $(addprefix $(DIRLIBFT),$(LIBNAME))

INCLUDE = ft_printf.h

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(LIBNAME) $(NAME)

-include $(INCLUDE))

bonus: $(LIBNAME) $(NAME)

$(NAME): $(OBJS) $(DEPS) $(LIBNAME)
	cp -p $(LIBNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $*.c -o $*.o

%.d : %.c $(INCLUDE)
	$(CC) -MM $(FLAGS) -c $*.c > $*.d

$(LIBNAME) : $(LIBFT)
	@cp -p $(LIBFT) $(LIBNAME)

$(LIBFT): 
	make -C$(DIRLIBFT) bonus

print:
	@echo $(INCLUDE)
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(NAME)
	@echo $(LIBFT)

clean:
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) $(HEAD_DEPS) $(HEAD_OBJS) $(TARGETLIB)
	make -C$(DIRLIBFT) clean

fclean:     clean
	$(RM) $(NAME) $(LIBFT) $(LIBNAME)

re:         fclean $(NAME) 

.PHONY: all re clean fclean re $(LIBFT) bonus
