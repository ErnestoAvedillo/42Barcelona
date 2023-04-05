NAME := philo

SRC := $(NAME)

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

-include $(DSPS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

$(DIR_OBJ_DST)%.o : $(SRCS) %(INCLUDE)
	mkdir -d $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -c $(DIR_SRC)*.c -o $(DIR_OBJ_DST)*.o 

$(DIR_OBJ_DST)%.d : $(SRCS) %(INCLUDE)
	mkdir -d $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -MM -c $(DIR_SRC)*.c -o $(DIR_OBJ_DST)*.o 



print:
	#echo INCLUDE: $(INCLUDE)
	#echo NAME: $(NAME)
	#echo SRC: $(SRCS)
