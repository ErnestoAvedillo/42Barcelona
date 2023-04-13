NAME := philo

SRC := $(NAME) philo_utils ft_isdigit ft_atoi

DIR_SRC := ./src/

DIR_OBJ_DST := ./obj_dst/

INCLUDE:= $(addprefix $(DIR_SRC),$(addsuffix .h, $(INCLUDE)))

SRCS:= $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS:= $(addprefix $(DIR_OBJ_DST),$(addsuffix .o,$(SRC)))
DSTS:= $(addprefix $(DIR_OBJ_DST),$(addsuffix .d,$(SRC)))

CC:= gcc

FLAGS:= -Werror -Wextra -Wall -O2 -fsanitize=address

RM= rm -rfd

all: $(NAME)

-include $(DSTS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o $(NAME) 

$(DIR_OBJ_DST)%.o : $(DIR_SRC)%.c $(DIR_OBJ_DST)%.d
	mkdir -p $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -static-libasan -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.o 

$(DIR_OBJ_DST)%.d : $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -MM -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.o 



print:
	#echo INCLUDE: $(INCLUDE)
	#echo NAME: $(NAME)
	#echo SRC: $(SRCS)
	#echo OBJS: $(OBJS)
	#echo DSTS: $(DSTS)
	#echo DIR_OBJ_DST: $(DIR_OBJ_DST)

PHONY: all re print
