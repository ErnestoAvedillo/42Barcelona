# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:29:34 by eavedill          #+#    #+#              #
#    Updated: 2022/10/07 16:29:41 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

all= $(NAME)

SRC = ft_printf ft_utoa ft_addrtoa

OBJS = $(addsuffix .o,$(SRC))

DEPS = $(addsuffix .d,$(SRC))

SRCS = $(addsuffix .c,$(SRC))


INCLUDE = $(NAME:.a=.h)

FLAGS = -Wall -Werror -Wextra

CC = gcc

$(NAME): $(OBJS) $(DEPS)
	ar -rcs $(NAME) $(OBJS) $(DEPS)

%.o : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $*.c -o $*.o

%.d : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $*.c > $*.d

all: $(NAME)

print:
	echo $(INCLUDE)
	echo $(SRCS)
	echo $(OBJS)
	echo $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) $(HEAD_DEPS) $(HEAD_OBJS)

fclean:     clean
	$(RM) $(NAME) $(BONUS)

re:         fclean $(NAME)

.PHONY: all re clean fclean re