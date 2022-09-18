# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/09/18 19:56:09 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_isalpha ft_isalnum ft_isdigit ft_isascii ft_isprint ft_strlen ft_memset ft_strlcpy ft_bzero ft_memmove ft_memcpy

SRCS = $(addsuffix .c , $(SRC))

HEAD = ./

OBJS = $(addsuffix .o , $(SRC))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = Libft.a

print:
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:		
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 
