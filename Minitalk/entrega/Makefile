NAME_CLI := client

NAME_SRV := server


SRC_DIR_CLI := ./src_cli/
SRC_DIR_SRV := ./src_srv/

INCLUDE_CLI := $(addprefix $(SRC_DIR_CLI), $(addsuffix .h, $(NAME_CLI)))
INCLUDE_SRV := $(addprefix $(SRC_DIR_SRV), $(addsuffix .h, $(NAME_SRV)))

OBJ_DST_DIR_CLI := ./obj_cli/
OBJ_DST_DIR_SRV := ./obj_srv/

SRC_CLI := $(NAME_CLI) client_utils

SRC_SRV := $(NAME_SRV) server_utils

SRCS_CLI := $(addprefix $(SRC_DIR_CLI), $(addsuffix .c, $(SRC_CLI)))
SRCS_SRV := $(addprefix $(SRC_DIR_SRV), $(addsuffix .c, $(SRC_SRV)))

OBJS_CLI := $(addprefix $(OBJ_DST_DIR_CLI), $(addsuffix .o, $(SRC_CLI)))
OBJS_SRV := $(addprefix $(OBJ_DST_DIR_SRV), $(addsuffix .o, $(SRC_SRV)))

DSTS_CLI := $(addprefix $(OBJ_DST_DIR_CLI), $(addsuffix .d, $(SRC_CLI)))
DSTS_SRV := $(addprefix $(OBJ_DST_DIR_SRV), $(addsuffix .d, $(SRC_SRV)))

#libraries
NAME_PRINTF := libftprintf.a
DIR_PRINTF := ./printf/
LIB_PRINTF := $(addprefix $(DIR_PRINTF),$(NAME_PRINTF))

NAME_GNXTL := get_next_line.a
DIR_GNXTL := ./nextline/
LIB_GNXTL := $(addprefix $(DIR_GNXTL),$(NAME_GNXTL))


RM := rm -rfd

CP := cp -p

CC := gcc

FLAGS := -Wall -Wextra -Werror


all: nextline printf $(NAME_CLI) $(NAME_SRV) 

-include $(DSTS_CLI) $(DSTS_SRV)

#Compile Client
$(NAME_CLI): $(OBJS_CLI) $(LIB_PRINTF) $(LIB_GNXTL)
	$(CC) $(FLAGS) $(OBJS_CLI) $(LIB_PRINTF) $(LIB_GNXTL) -o $(NAME_CLI)

$(OBJ_DST_DIR_CLI)%.o : $(SRCS_CLI) $(DSTS_CLI) $(INCLUDE_CLI)
	mkdir -p $(OBJ_DST_DIR_CLI)
	@echo paso 4 $(SRC_DIR_CLI)$*.c
	$(CC) $(FLAGS) -c $(SRC_DIR_CLI)$*.c -o $(OBJ_DST_DIR_CLI)$*.o

$(OBJ_DST_DIR_CLI)%.d:  $(SRCS_CLI) $(INCLUDE_CLI)
	mkdir -p $(OBJ_DST_DIR_CLI)
	@echo paso 31 $(SRC_DIR_CLI)$*.c
	$(CC) -MM $(FLAGS) -c $(SRC_DIR_CLI)$*.c > $(OBJ_DST_DIR_CLI)$*.d

#comìle server
$(NAME_SRV): $(OBJS_SRV) $(LIB_PRINTF) $(LIB_GNXTL)
	$(CC) $(FLAGS) $(OBJS_SRV) $(LIB_PRINTF) $(LIB_GNXTL) -o $(NAME_SRV)

$(OBJ_DST_DIR_SRV)%.o: $(SRCS_SRV) $(DSTS_SRV) $(INCLUDE_SRV)
	mkdir -p $(OBJ_DST_DIR_SRV)
	@echo paso 2 $(SRC_DIR_SRV)$*.c
	@echo $(SRC_DIR_SRV)$*.c
	$(CC) $(FLAGS) -c $(SRC_DIR_SRV)$*.c -o $(OBJ_DST_DIR_SRV)$*.o

$(OBJ_DST_DIR_SRV)%.d: $(SRCS_SRV) $(INCLUDE_SRV)
	mkdir -p $(OBJ_DST_DIR_SRV)
	@echo paso 1 $(SRC_DIR)$*.c
	$(CC) -MM $(FLAGS) -c $(SRC_DIR_SRV)$*.c > $(OBJ_DST_DIR_SRV)$*.d

# Compiling getnextline.
nextline:
	make -C$(DIR_GNXTL)

# Compiling printf.
printf:
	make -C$(DIR_PRINTF)

clean:
	$(RM) $(OBJ_DST_DIR_CLI) $(OBJ_DST_DIR_SRV)
	make -C$(DIR_GNXTL) clean
	make -C$(DIR_PRINTF) clean

fclean: clean
	$(RM) $(NAME_CLI) $(NAME_SRV) $(LIB_GNXTL) $(LIB_PRINTF)

re: fclean all

print:
	@echo SRC_DIR: $(SRC_DIR_CLI)
	@echo SRC_DIR: $(SRC_DIR_SRV)
	@echo SRCS_CLI: $(SRCS_CLI)
	@echo SRCS_SRV: $(SRCS_SRV)
	@echo OBJS_CLI: $(OBJS_CLI)
	@echo OBJS_SRV: $(OBJS_SRV)
	@echo DSTS_CLI: $(DSTS_CLI)
	@echo DSTS_SRV: $(DSTS_SRV)
	@echo OBJ_DST_DIR_CLI: $(OBJ_DST_DIR_CLI)
	@echo OBJ_DST_DIR_SRV: $(OBJ_DST_DIR_SRV)
	@echo NAME_PRINTF: $(NAME_PRINTF)
	@echo DIR_PRINTF: $(DIR_PRINTF)
	@echo LIB_PRINTF: $(LIB_PRINTF)
	@echo NAME_GNXTL: $(NAME_GNXTL)
	@echo DIR_GNXTL: $(DIR_GNXTL)
	@echo LIB_GNXTL: $(LIB_GNXTL)

.PHONY: print all re clean fclean nextline printf