# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:29:34 by eavedill          #+#    #+#              #
#    Updated: 2022/12/29 14:29:55 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC :=  ft_printf_bonus ft_utoa_bonus ft_addrtoa_bonus ft_printf_args_bonus ft_print_ext_bonus \
		fill_list_bonus fill_list_utl_bonus ft_printf_utl_bonus ft_print_frmt_bonus ft_prnitf_writ_ext_bonus \
		ft_print_suf_bonus ft_print_chrs_bonus ft_printf_chk_utl_bonus ft_printf_chk_utl2_bonus

OBJS := $(addsuffix .o,$(SRC))

DEPS := $(addsuffix .d,$(SRC))

SRCS := $(addsuffix .c,$(SRC))

DIRLIBFT := ../libft/
LIBNAME := libft.a
LIBFT := $(addprefix $(DIRLIBFT),$(LIBNAME))

INCLUDE := ft_printf_bonus.h

FLAGS := -Wall -Werror -Wextra

CC := gcc

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
	@echo $(NAMES)
	@echo $(LIBFT)

clean:
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) $(HEAD_DEPS) $(HEAD_OBJS) $(TARGETLIB)
	make -C$(DIRLIBFT) clean

fclean:     clean
	$(RM) $(NAME) $(LIBFT) $(LIBNAME)
	make -C$(DIRLIBFT) fclean

re:         fclean $(NAME) 

.PHONY: all re clean fclean re $(LIBFT) bonus
