# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/09/16 18:48:57 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_isalpha ft_isalnum

SRCS = $(addsuffix .c , $(SRC))

HEAD = ./

OBJS = $(addsuffix .o , $(SRC))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I

NAME = Libft.a

print:
	ls
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:		$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all print clean fclean re 
