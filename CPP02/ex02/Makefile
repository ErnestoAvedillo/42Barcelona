# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:03:29 by eavedill          #+#    #+#              #
#    Updated: 2023/10/01 15:03:32 by eavedill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		:=	\033[1;97m
RED			:=	\033[1;91m
GREEN		:=	\033[1;92m
YELLOW		:=	\033[1;93m
BLUE		:=	\033[1;94m
PINK		:=	\033[1;95m
CIAN		:=	\033[1;96m

NAME := fixed

SRC := main Fixed test_inc_dec test_aritm test_comp test_min_max

CLAS := Fixed

INC := main colors

DIRSRC := ./src/

DIRINC := ./inc/

OBJDST_DIR := ./objdst_dir/

SRCS := $(addprefix $(DIRSRC), $(addsuffix .cpp,$(SRC)))
OBJS := $(addprefix $(OBJDST_DIR), $(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(OBJDST_DIR), $(addsuffix .d,$(SRC)))
INCS := $(addprefix $(DIRINC), $(addsuffix .h,$(INC)))
CLASS := $(addprefix $(DIRINC), $(addsuffix .hpp,$(CLAS)))

RM := rm -rfd

CC:= c++

FLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME) Makefile
	
$(NAME): $(DSTS) $(OBJS) 
	@printf "\rLinking: $(NAME)                                                  \n"
	@sleep 0.1
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDST_DIR)%.o: $(DIRSRC)%.cpp $(OBJDST_DIR)%.d
	@mkdir -p $(OBJDST_DIR)
	@printf "$(GREEN)\rCompiling $*.o: $(notdir $<).                             $(RESET)"
	@sleep 0.2
	@$(CC) $(FLAGS) -c $(DIRSRC)$*.cpp -o $(OBJDST_DIR)$*.o 

$(OBJDST_DIR)%.d: $(DIRSRC)%.cpp
	@mkdir -p $(OBJDST_DIR)
	@printf "$(BLUE)\rCreating Dependencies $*.d: $(notdir $<).                   $(RESET)"
	@sleep 0.3
	@set -e; rm -f $@; \
	$(CC) -M $(FLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

print:
	@echo NAME: $(NAME)
	@echo SRCS: $(SRCS)
	@echo INCS: $(INCS)
	@echo OBJS: $(OBJS)
	@echo DSTS: $(DSTS)
	@echo OBJDST_DIR: $(OBJDST_DIR)
	@echo DIRSRC: $(DIRSRC)
	@echo DIRINC: $(DIRINC)

clean:
	@printf "$(RED)Removing objects folder $(OBJDST_DIR).$(RESET)\n"
	$(RM) $(OBJDST_DIR)

fclean: clean
	@printf "$(RED)\rRemoving executable object $(NAME).$(RESET)\n"
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re print

.SILENT:

ifeq (,$(findstring clean,$(MAKECMDGOALS)))
ifeq (,$(findstring re,$(MAKECMDGOALS)))
-include $(DSTS)
endif
endif
