# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/09/24 16:03:27 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_isalpha ft_isalnum ft_isdigit ft_isascii ft_isprint \
	 ft_strlen ft_memset ft_strlcpy ft_strlcat ft_bzero ft_memmove ft_memcpy \
	 ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	 ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
	 ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd 


SRCS = $(addsuffix .c , $(SRC))

HEAD = ./

OBJS = $(addsuffix .o , $(SRC))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = Libft.a


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

print:
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

.PHONY:		all clean fclean re 
