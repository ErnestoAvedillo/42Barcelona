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
SRC = test_ft_isalpha test_ft_isalnum test_ft_isdigit test_ft_isascii test_ft_isprint \
	 test_ft_strlen test_ft_memset test_ft_strlcpy test_ft_strlcat test_ft_bzero test_ft_memmove \
	 test_ft_memcpy test_ft_toupper test_ft_tolower test_ft_strchr test_ft_strrchr \
	 test_ft_strncmp test_ft_memchr test_ft_memcmp test_ft_strnstr test_ft_atoi test_ft_calloc \
	 test_ft_strdup test_ft_substr test_ft_strjoin test_ft_strtrim test_ft_split test_ft_itoa \
	 test_ft_strmapi test_ft_striteri test_ft_putchar_fd test_ft_putstr_fd test_ft_putendl_fd \
	 test_ft_putnbr_fd 

LIB_FILES = ../Libft/libft.a

SRCS = $(addsuffix .c , $(SRC))

HEAD = ./

OBJS = $(addsuffix .o , $(SRC))

DEPEN = $(addsuffix .d , $(SRC))

LIBS = -I. -I../Libft

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

NAME = test_libft.a

-include $(addsuffix .d , $(SRC))

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIB_FILES) 

%.o: %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o $(LIBS)
	$(CC) -MM $(CFLAGS)  $*.c > $*.d $(LIBS)

all: $(NAME)

clean:		
	$(RM) $(OBJS) $(DEPEN) 

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

print:
	@echo "listado de app " $(NAME)
	@echo "listado de obcts " $(OBJS)
	@echo "listado de src " $(SRC)
	@echo "listado de srcs " $(SRCS)

.PHONY:		all clean fclean re 
