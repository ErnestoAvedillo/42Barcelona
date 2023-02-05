NAME := fractol
NAME_LNX := fractol

SRC := fractol
DIR_SRC := ./srcs/

OBJDST_DIR := ./objdst/
#source files mac
SRCS_MAN := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .o,$(SRC)))
DPNS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .d,$(SRC)))
INCLUDE := $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))
#source files linux
SRCS_MAN_LNX := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN_LNX := $(addprefix $(OBJDST_DIR),$(addsuffix .o,$(SRC)))
DPNS_MAN_LNX := $(addprefix $(OBJDST_DIR),$(addsuffix .d,$(SRC)))
INCLUDE_LNX := $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))
#libraries
#libft
LIBFT_NAME := libft.a
DIR_LIBFT := ./libft/
LIBFT = $(addprefix $(DIR_LIBFT),$(LIBFT_NAME))
#minilibX
LIBX_NAME := libmlx.dylib
DIR_LIBX := ./mlx/
LIBX = $(addprefix $(DIR_LIBX),$(LIBX_NAME))
#link elements
LIBX_LNK :=  -Lmlx -lmlx -framework OpenGL -framework AppKit 
RM := rm -rfd
CC := gcc 
FLAGS := -Wall -Werror -Wextra

all : $(NAME)

-include:$(DPNS_MAN)

$(NAME): $(OBJS_MAN) $(DPNS_MAN) $(LIBFT_NAME) $(LIBX_NAME)
	$(CC) $(FLAG) $(LIBX_LNK) $(OBJS_MAN) -o $(NAME)

$(OBJDST_DIR)%.o $(OBJDST_DIR)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(OBJDST_DIR)
	$(CC) $(FLAG)  -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR)$*.o
	$(CC) -MM $(FLAG)  -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c > $(OBJDST_DIR)$*.d

#linux: $(NAME_LNX)

#$(OBJS_MAN): $(OBJS_MAN) $(DPNS_MAN) $(LIBFT_NAME) $(LIBX_NAME)
#	$(CC) $(FLAG) -I/usr/include/ $(LIBX_LNK) $(OBJS_MAN) -o $(NAME_LNX)

#$(NAME_LNX): $(OBJS_MAN)
#	$(CC) $(OBJS_MAN) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_LNX)

$(LIBFT_NAME):$(LIBFT)
	cp -p $(LIBFT) $(LIBFT_NAME)

$(LIBFT):
	make -C $(DIR_LIBFT) bonus

$(LIBX_NAME) : $(LIBX)
	cp -p $(LIBX) $(LIBX_NAME)

$(LIBX):
	make -sC $(DIR_LIBX)

print:
	@echo $(DIR_SRC)
	@echo $(SRCS_MAN)
	@echo $(OBJS_MAN)
	@echo $(DPNS_MAN)
	@echo $(INCLUDE)
	@echo $(LIBFT_NAME)
	@echo $(DIR_LIBFT)
	@echo $(LIBFT)
	@echo $(LIBX_NAME)
	@echo $(DIR_LIBX)
	@echo $(LIBX)

clean:
	$(RM) $(OBJDST_DIR)
	make -C$(DIR_LIBFT) clean
	make -C$(DIR_LIBX) clean

fclean:
	make -C$(DIR_LIBFT) fclean
	make -C$(DIR_LIBX) clean
	$(RM) $(LIBFT_NAME) $(NAME) $(LIBX_NAME)

re: fclean all

PHONY: all bonus clean fclean re $(LIBFT) $(LIBX_NAME)