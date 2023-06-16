NAME := philo_bonus

SRC := $(NAME) philo_utils_bonus ft_isdigit_bonus ft_atoi_bonus philo_mem_bonus \
	philo_print_bonus philo_free_bonus philo_init_bonus philo_work_proc_bonus \
	philo_time_tool_bonus

DIR_SRC := ./src_bonus/

DIR_OBJ_DST := ./obj_dst_bonus/

INC = $(NAME) colors

INCLUDE:= $(addprefix $(DIR_SRC),$(addsuffix .h, $(INC)))

SRCS:= $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS:= $(addprefix $(DIR_OBJ_DST),$(addsuffix .o,$(SRC)))
DSTS:= $(addprefix $(DIR_OBJ_DST),$(addsuffix .d,$(SRC)))

CC:= gcc

FLAGS:= -Werror -Wextra -Wall -O2  -g

VISUAL = MANDAT
#-fsanitize=datarace-fsanitize=address
RM := rm -rfd

all:  $(NAME)

table: VISUAL = VISIO
table:  $(NAME)

control: VISUAL = CONTROL
control:$(NAME)

-include $(DSTS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -static-libsan  $(OBJS) -o $(NAME) 
#$(DIR_OBJ_DST)%.d
$(DIR_OBJ_DST)%.o: $(DIR_SRC)%.c 
	mkdir -p $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -D $(VISUAL)  -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.o

$(DIR_OBJ_DST)%.d: $(DIR_SRC)*.c $(INCLUDE)
	mkdir -p $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -MM -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.d 

clean:
	$(RM) $(DIR_OBJ_DST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

print:
	#echo INCLUDE: $(INCLUDE)
	#echo NAME: $(NAME)
	#echo SRC: $(SRCS)
	#echo OBJS: $(OBJS)
	#echo DSTS: $(DSTS)
	#echo DIR_OBJ_DST: $(DIR_OBJ_DST)

PHONY: all re clean fclean print
