NAME := fractol
NAME_LNX := fractol_lnx

SRC := fractol fract_calc complex_oper0 complex_oper1
DIR_SRC := ./srcs/

OBJDST_DIR := ./objdst/
#source files mac
SRCS_MAN := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .o,$(SRC)))
DPNS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .d,$(SRC)))
INCLUDE := $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))
#source files linux
OBJDST_DIR_LNX := ./objdstlnx/
SRCS_MAN_LNX := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN_LNX := $(addprefix $(OBJDST_DIR_LNX),$(addsuffix .o,$(SRC)))
DPNS_MAN_LNX := $(addprefix $(OBJDST_DIR_LNX),$(addsuffix .d,$(SRC)))
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
#minilibX Linux
LIBX_NAME_LNX := libmlx.a
DIR_LIBX_LNX := ./mlx/
LIBX_LNX = $(addprefix $(DIR_LIBX),$(LIBX_NAME_LNX))
#link elements
LIBX_LNK :=  -Lmlx -lmlx -framework OpenGL -framework AppKit 
RM := rm -rfd
CC := gcc 
FLAGS := -Wall -Werror -Wextra

all : $(NAME)

-include:$(DPNS_MAN) $(DPNS_MAN_LNX)

#MAC compilation
$(NAME): $(OBJS_MAN) $(LIBFT_NAME) $(LIBX_NAME)
	$(CC) $(FLAGS) $(LIBX_LNK) $(OBJS_MAN) -o $(NAME)

$(OBJDST_DIR)%.o: $(DIR_SRC)%.c $(OBJDST_DIR)%.d
	mkdir -p $(OBJDST_DIR)
	$(CC) $(FLAGS)  -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR)$*.o

$(OBJDST_DIR)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(OBJDST_DIR)
	$(CC) -MM $(FLAGS)  -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c > $(OBJDST_DIR)$*.d

$(LIBX_NAME) : $(LIBX)
	cp -p $(LIBX) $(LIBX_NAME)

$(LIBX):
	make -sC $(DIR_LIBX)

#linux compilation
linux: $(NAME_LNX)

$(NAME_LNX): $(OBJS_MAN_LNX) $(LIBFT_NAME) $(LIBX_NAME_LNX)
	$(CC) $(FLAGS) $(OBJS_MAN_LNX) $(LIBX_NAME_LNX) -L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lm -lz -o $(NAME_LNX)

$(OBJDST_DIR_LNX)%.o: $(DIR_SRC)%.c $(OBJDST_DIR_LNX)%.d
	mkdir -p $(OBJDST_DIR_LNX)
	$(CC) $(FLAGS) -I/usr/include/ -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR_LNX)$*.o

$(OBJDST_DIR_LNX)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(OBJDST_DIR_LNX)
	$(CC) -MM $(FLAGS)  -I $(DIR_LIBFT) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c > $(OBJDST_DIR_LNX)$*.d

$(LIBX_NAME_LNX) : $(LIBX_LNX)
	cp -p $(LIBX_LNX) $(LIBX_NAME_LNX)

$(LIBX_LNX):
	make -f Makefile.gen -sC $(DIR_LIBX_LNX)

#
#common compilation

$(LIBFT_NAME):$(LIBFT)
	cp -p $(LIBFT) $(LIBFT_NAME)

$(LIBFT):
	make -C $(DIR_LIBFT) bonus



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
	$(RM) $(OBJDST_DIR) $(OBJDST_DIR_LNX)
	make -C$(DIR_LIBFT) clean
	make -C$(DIR_LIBX) clean

fclean:
	make -C$(DIR_LIBFT) fclean
	make -C$(DIR_LIBX) clean
	$(RM) $(LIBFT_NAME) $(NAME) $(NAME_LNX) $(LIBX_NAME) $(LIBX_NAME_LNX)

re: fclean all

PHONY: all bonus clean fclean re $(LIBFT) $(LIBX_NAME)