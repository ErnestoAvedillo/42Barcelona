NAME_CLI := client
INCLUDE_CLI := client.h

NAME_SRV := server
INCLUDE_SRV := server.h

SRC_DIR := ./srcs/

OBJ_DST_DIR := ./obj/

SRC_CLI := $(NAME_CLI) client_utils

SRC_SRV := $(NAME_SRV) server_utils

SRCS_CLI := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_CLI)))
SRCS_SRV := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SRV)))

OBJS_CLI := $(addprefix $(OBJ_DST_DIR), $(addsuffix .o, $(SRC_CLI)))
OBJS_SRV := $(addprefix $(OBJ_DST_DIR), $(addsuffix .o, $(SRC_SRV)))

DSTS_CLI := $(addprefix $(OBJ_DST_DIR), $(addsuffix .d, $(SRC_CLI)))
DSTS_SRV := $(addprefix $(OBJ_DST_DIR), $(addsuffix .d, $(SRC_SRV)))

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


all: $(NAME_CLI) $(NAME_SRV)


#Compile Client
$(NAME_CLI): $(OBJS_CLI) 
	$(CC) $(FLAGS) $(NAME_PRINTF) $(NAME_GNXTL) $(OBJS_CLI) -o $(NAME_CLI)

$(OBJS_CLI): $(DSTS_CLI) $(INCLUDE_CLI)
	$(CC) $(FLAGS) -c $(DIR_SRCS)$*.c -o $(OBJ_DST_DIR)$*.o

$(DSTS_CLI): $(SRCS_CLI) $(INCLUDE_CLI)
	$(CC) -MM $(FLAGS) -c $(DIR_SRCS)$*.c > $(OBJ_DST_DIR)$*.d

#comìle server
$(NAME_SRV): $(OBJS_SRV) 
	$(CC) $(FLAGS) $(NAME_PRINTF) $(NAME_GNXTL) $(OBJS_SRV) -o $(NAME_SRV)

$(OBJS_SRV): $(DSTS_SRV) $(INCLUDE_SRV)
	$(CC) $(FLAGS) -c $(DIR_SRCS)$*.c -o $(OBJ_DST_DIR)$*.o

$(DSTS_SRV): $(SRCS_SRV) $(INCLUDE_SRV)
	$(CC) -MM $(FLAGS) -c $(DIR_SRCS)$*.c > $(OBJ_DST_DIR)$*.d

# Compiling getnextline.
$(NAME_GNXTL): $(LIB_GNXTL)
	$(CP) $(LIB_GNXTL) $(NAME_GNXTL)
	
$(LIB_GNXTL):
	mane -C$(DIR_GNXTL)

# Compiling printf.
$(NAME_PRINTF): $(LIB_PRINTF)
	$(CP) $(LIB_PRINTF) $(NAME_PRINTF)
	
$(LIB_PRINTF):
	mane -C$(DIR_PRINTF)

clean:
	$(RM) $(OBJ_DST_DIR)
	make -C$(DIR_GNXTL) clean
	make -C$(DIR_PRINTF) clean

fclean: clean
	$(RM) $(NAME_CLI) $(NAME_GNXTL) $(NAME_PRINTF) $(NAME_SRV) $(LIB_GNXTL) $(LIB_PRINTF)

re: fclean all

print:
	@echo SRCS_CLI: $(SRCS_CLI)
	@echo SRCS_SRV :$(SRCS_SRV)
	@echo OBJS_CLI :$(OBJS_CLI)
	@echo OBJS_SRV: $(OBJS_SRV)
	@echo DSTS_CLI: $(DSTS_CLI)
	@echo DSTS_SRV: $(DSTS_SRV)
	@echo NAME_PRINTF: $(NAME_PRINTF)
	@echo DIR_PRINTF: $(DIR_PRINTF)
	@echo LIB_PRINTF: $(LIB_PRINTF)
	@echo NAME_GNXTL: $(NAME_GNXTL)
	@echo DIR_GNXTL: $(DIR_GNXTL)
	@echo LIB_GNXTL: $(LIB_GNXTL)

.PHONY: print all re clean fclean $(LIB_GNXTL) $(LIB_PRINTF)