# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:19:18 by eavedill          #+#    #+#              #
#    Updated: 2022/10/10 09:31:56 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

SRC = ft_isalpha ft_isalnum ft_isdigit ft_isascii ft_isprint \
	 ft_strlen ft_memset ft_strlcpy ft_strlcat ft_bzero ft_memmove ft_memcpy \
	 ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	 ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
	 ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd 

SRC_BONUS = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
	 ft_lstlast ft_lstmap ft_lstnew ft_lstsize

INCLUDE = libft.h


SRCS = $(addsuffix .c , $(SRC))

OBJS = $(addsuffix .o , $(SRC))

DEPEN = $(addsuffix .d , $(SRC))

SRCS_BONUS = $(addsuffix .c , $(SRC_BONUS))

OBJS_BONUS = $(addsuffix .o , $(SRC_BONUS))

DEPEN_BONUS = $(addsuffix .d , $(SRC_BONUS))

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):	$(OBJS) $(DEPEN) 
	ar rcs $(NAME) $(OBJS) 

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I. -c $*.c -o $*.o
	$(CC) -MM $(CFLAGS) -I.  $*.c > $*.d

bonus: $(OBJS) $(DEPEN) $(OBJS_BONUS) $(DEPEN_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS) $(DEPEN_BONUS) $(OBJS) $(DEPEN)

clean:		
	$(RM) $(OBJS) $(DEPEN) $(DEPEN_BONUS) $(OBJS_BONUS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 
