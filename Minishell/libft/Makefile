# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 12:41:57 by eavedill          #+#    #+#              #
#    Updated: 2022/12/18 12:58:29 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := libft.a

BONUS := .bonus

SRC := ft_isalpha ft_isalnum ft_isdigit ft_isascii ft_isprint \
	  ft_strlen ft_memset ft_strlcpy ft_strlcat ft_bzero ft_memmove ft_memcpy \
	  ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	  ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
	  ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	  ft_max ft_min ft_abs ft_ispositive ft_issamesign ft_isodd ft_strsort_arr \
	  ft_len_str_arr ft_cpy_str_arr

SRC_BONUS := ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
			ft_lstlast ft_lstmap ft_lstnew ft_lstsize

INCLUDE := libft.h

HEAD_OBJS := ./obj/
HEAD_DEPS := ./dep/

SRCS = $(addprefix $(HEAD_OBJS), $(addsuffix .c , $(SRC)))

OBJS = $(addprefix $(HEAD_OBJS), $(addsuffix .o , $(SRC)))
DEPS = $(addprefix $(HEAD_DEPS), $(addsuffix .d , $(SRC)))

SRCS_BONUS := $(addsuffix .c , $(SRC_BONUS))

OBJS_BONUS := $(addprefix $(HEAD_OBJS), $(addsuffix .o , $(SRC_BONUS)))
DEPS_BONUS := $(addprefix $(HEAD_DEPS), $(addsuffix .d , $(SRC_BONUS)))

CC = gcc

RM = rm -rfd

CFLAGS = -Wall -Wextra -Werror -I.

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

-include: (DEPS)

-include: (DEPS_BONUS)

$(HEAD_OBJS)%.o $(HEAD_DEPS)%.d : %.c $(INCLUDE)
	@mkdir -p  $(HEAD_OBJS)
	@mkdir -p  $(HEAD_DEPS)
	@printf "\rCompiling: $(notdir $<).\r"
	@$(CC) $(CFLAGS) -c $*.c -o $(HEAD_OBJS)$*.o
	@$(CC) -MM $(CFLAGS) -c $*.c > $(HEAD_DEPS)$*.d

all:$(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS) $(OBJS_BONUS) $(INCLUDE)
	@ar -rcs $(NAME) $(OBJS_BONUS) $(OBJS)
	@touch $@

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) $(HEAD_DEPS) $(HEAD_OBJS)

fclean:     clean
	@$(RM) $(BONUS) $(NAME) 

re:         fclean $(NAME)

.PHONY:     all clean fclean re bonus
