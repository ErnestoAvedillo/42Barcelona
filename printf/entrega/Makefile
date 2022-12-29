# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 20:19:09 by eavedill          #+#    #+#              #
#    Updated: 2022/12/27 20:19:12 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

DIR_BONUS := ./bonus/
NAME_DIR_BONUS := $(addsuffix $(NAME),$(DIR_BONUS))
BONUS := .bonus

DIR_MANDATORY := ./mandatory/
NAME_DIR_MANDAT := $(addsuffix $(NAME),$(DIR_MANDATORY))
MANDAT:= .mandat 

RM := rm -rfd
#---------------------------------
all: $(NAME)

$(NAME): $(MANDAT)

$(MANDAT):$(NAME_DIR_MANDAT)
	cp -p $(NAME_DIR_MANDAT) $(NAME)
	touch $(MANDAT)

$(NAME_DIR_MANDAT):	
	make -C$(DIR_MANDATORY)
#---------------------------------
bonus: $(BONUS)

$(BONUS): $(NAME_DIR_BONUS)
	cp -p $(NAME_DIR_BONUS) $(NAME)
	touch $(BONUS)

$(NAME_DIR_BONUS):
	make -C$(DIR_BONUS)

clean:
	make -C$(DIR_BONUS) clean
	make -C$(DIR_MANDATORY) clean

fclean: 
	make -C$(DIR_MANDATORY) fclean
	make -C$(DIR_BONUS) fclean
	$(RM) $(NAME) $(NAME_M) $(NAME_B) $(MANDAT) $(BONUS)

re: fclean
	make all
	
.PHONY: all bonus re fclean clean $(NAME) $(NAME_DIR_MANDAT) $(NAME_DIR_BONUS)

print:
	@echo NAME:$(NAME)
	@echo NAME_M:$(NAME_M)
	@echo DIR_MANDATORY:$(DIR_MANDATORY)
	@echo NAME_DIR_MANDAT:$(NAME_DIR_MANDAT)
	@echo MANDAT:$(MANDAT)
	@echo NAME_B:$(NAME_B)
	@echo DIR_BONUS:$(DIR_BONUS)
	@echo NAME_DIR_BONUS:$(NAME_DIR_BONUS)
	@echo BONUS:$(BONUS)
