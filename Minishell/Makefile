NAME = minishell

SRC = $(NAME) cmd_echo cmd_cd cmd_env cmd_exit cmd_export cmd_pwd cmd_unset init_vars \
	free_vars utils utils2 work_command cmd_setenv check_cmd_line check_quotes \
	tokenize token_utils token_utils3 token_utils2 print_var replace_env_var cmd_exec adm_signal \
	actualize_env concat_cmd get_cmd ft_leninstr adm_redirections adm_redirections1 ft_str_arr_add \
	ft_str_arr_rem adm_file_redir check_delimiter check_delimiter1 ft_split_instr ft_strrmstr \
	print_err admin_fd0 admin_fd1 cmd_export_print check_syntax check_redir check_pipes ft_strrmallchr \
	get_var_name parse_input1 parse_input2 parse_input3 parse_input4 parse_utils1 cmd_read check_delimiter2
	
#añadir nombres de ficheros.c  aqui

INC = $(NAME) colors #añadir nombres de ficheros.h  aqui

DIR_SRC = ./src/

INCDIR = ./inc/

DIR_OBJ_DST = ./obj_dst/

SRCS = $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
SRCS = $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS = $(addprefix $(DIR_OBJ_DST),$(addsuffix .o,$(SRC)))
DSTS = $(addprefix $(DIR_OBJ_DST),$(addsuffix .d,$(SRC)))
INCLUDE:= $(addprefix $(INCDIR),$(addsuffix .h, $(INC)))

#NEXTLINE LIBRARY
DIR_NEXTLINE = ./Nextline/
NEXTLINE = $(addprefix $(DIR_NEXTLINE),get_next_line.a)

#FT_PRINTF LIBRARY
DIR_PRINTF = ./ft_printf/
FT_PRINTF = $(addprefix $(DIR_PRINTF),libftprintf.a)

CC:= gcc

FLAGS:= -Werror -Wextra -Wall -O2 -g $(SANIT1)

#-fsanitize=datarace -fsanitize=address
RM := rm -rfd

#readline flags
all: LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
all: COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
all: Makefile ftprint nextline $(NAME)


all_lk:SANIT1 = -fsanitize=address
all_lk:SANIT2 = -static-libsan
all_lk: all

linux: LINKING_FLAGS = -lreadline -L/usr/local/lib
linux: COMFILE_FLAGS = -I/usr/local/include
linux: Makefile ftprint nextline $(NAME)

linux_lk: SANIT1 = -fsanitize=address
linux_lk: SANIT2 = -static-libasan
linux_lk: linux

-include $(DSTS)

$(NAME): $(OBJS) $(NEXTLINE) $(FT_PRINTF) 
	$(CC) $(FLAGS) $(COMFILE_FLAGS)  $(SANIT1) -v $(OBJS) -o $(NAME) $(FT_PRINTF) $(NEXTLINE) $(LIBFT) ${LINKING_FLAGS}

#-static-libsan 
$(DIR_OBJ_DST)%.o: $(DIR_SRC)%.c $(DIR_OBJ_DST)%.d
	@mkdir -p $(DIR_OBJ_DST)
	@printf "\rCompiling: $(notdir $<).\r"
	@$(CC) $(FLAGS) $(COMFILE_FLAGS) -I$(INCDIR) $(SANIT2) -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.o 

$(DIR_OBJ_DST)%.d: $(DIR_SRC)%.c $(INCLUDE)
	@mkdir -p $(DIR_OBJ_DST)
	@$(CC) $(FLAGS) -I$(INCDIR) -MM -c $(DIR_SRC)$*.c -o $(DIR_OBJ_DST)$*.d 

ftprint:
	make -C$(DIR_PRINTF)

nextline:
	make -C$(DIR_NEXTLINE)

clean:
	@$(RM) $(DIR_OBJ_DST)
	make -C $(DIR_NEXTLINE) clean
	make -C $(DIR_PRINTF) clean

fclean: clean
	@$(RM) $(NAME)
	make -C $(DIR_NEXTLINE) fclean
	make -C $(DIR_PRINTF) fclean

re: fclean all

re_lk: fclean all_lk

linux_re:   fclean linux

print:
	@echo INCLUDE: $(INCLUDE)
	@echo NAME: $(NAME)
	@echo SRC: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo DSTS: $(DSTS)
	@echo DIR_OBJ_DST: $(DIR_OBJ_DST)
	@echo INCDIR: $(INCDIR)
	@echo INCLUDE: $(INCLUDE)
	@echo FT_PRINTF: $(FT_PRINTF)
	@echo DIR_PRINTF: $(DIR_PRINTF)
	@echo NEXTLINE: $(NEXTLINE)
	@echo DIR_NEXTLINE: $(DIR_NEXTLINE)

.PHONY: all re clean fclean print libft ftprint nextline linux_lk all_lk re_lk linux
