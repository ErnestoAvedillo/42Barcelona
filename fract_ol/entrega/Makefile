NAME := fractol
NAME_LNX := fractol_lnx

SRC := fractol fractol_utils mandelbrot complex_oper0 complex_oper1 fractol_draw close_win key_events_mac mouse_events julia palette burning_ship tricorn
SRC_LNX := fractol_lnx fractol_utils mandelbrot complex_oper0 complex_oper1 fractol_draw close_win key_events_lnx mouse_events julia palette burning_ship tricorn
DIR_SRC := ./srcs/

OBJDST_DIR := ./objdst/
#source files mac
INC = key_mouse_cod_mac
SRCS_MAN := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .o,$(SRC)))
DPNS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .d,$(SRC)))
INCLUDE := $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME))) $(addprefix $(DIR_SRC),$(addsuffix .h,$(INC)))
#source files linux
INC_LNX = key_mouse_cod_lnx
OBJDST_DIR_LNX := ./objdstlnx/
SRCS_MAN_LNX := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC_LNX)))
OBJS_MAN_LNX := $(addprefix $(OBJDST_DIR_LNX),$(addsuffix .o,$(SRC_LNX)))
DPNS_MAN_LNX := $(addprefix $(OBJDST_DIR_LNX),$(addsuffix .d,$(SRC_LNX)))
INCLUDE_LNX := $(addprefix $(DIR_SRC),$(addsuffix .h,$(INC_LNX)))
#libraries
#printf
PRINTF_NAME := libftprintf.a
DIR_PRINTF := ./printf/
PRINTF = $(addprefix $(DIR_PRINTF),$(PRINTF_NAME))
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
FLAGS := -Wall -Werror -Wextra -O2

all : $(NAME)

-include:$(DPNS_MAN) $(DPNS_MAN_LNX)

#MAC compilation
$(NAME): $(OBJS_MAN) $(PRINTF_NAME) $(LIBX_NAME)
	$(CC) $(FLAGS) $(LIBX_LNK) $(OBJS_MAN) $(PRINTF_NAME) -o $(NAME)

$(OBJDST_DIR)%.o: $(DIR_SRC)%.c $(OBJDST_DIR)%.d
	mkdir -p $(OBJDST_DIR)
	$(CC) $(FLAGS) -D KEY_MOUSE_COD_MAC_H  -I $(DIR_PRINTF) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR)$*.o

$(OBJDST_DIR)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(OBJDST_DIR)
	$(CC) -MM $(FLAGS)  -I $(DIR_PRINTF) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c > $(OBJDST_DIR)$*.d

$(LIBX_NAME) : $(LIBX)
	cp -p $(LIBX) $(LIBX_NAME)

$(LIBX):
	make -sC $(DIR_LIBX)

#linux compilation
linux: $(NAME_LNX)

$(NAME_LNX): $(PRINTF_NAME) $(LIBX_NAME_LNX) $(OBJS_MAN_LNX) 
	$(CC) $(FLAGS) $(OBJS_MAN_LNX) $(LIBX_NAME_LNX) $(PRINTF_NAME) -L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lm -lz -o $(NAME_LNX)

$(OBJDST_DIR_LNX)%.o: $(DIR_SRC)%.c $(OBJDST_DIR_LNX)%.d
	mkdir -p $(OBJDST_DIR_LNX)
	$(CC) $(FLAGS) -D KEY_MOUSE_COD_LNX_H -I/usr/include/ -I $(DIR_PRINTF) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR_LNX)$*.o

$(OBJDST_DIR_LNX)%.d: $(DIR_SRC)%.c $(INCLUDE)
	mkdir -p $(OBJDST_DIR_LNX)
	$(CC) -MM $(FLAGS)  -I $(DIR_PRINTF) -I $(DIR_LIBX) -c $(DIR_SRC)$*.c > $(OBJDST_DIR_LNX)$*.d

$(LIBX_NAME_LNX) : $(LIBX_LNX)
	cp -p $(LIBX_LNX) $(LIBX_NAME_LNX)

$(LIBX_LNX):
	make -f Makefile.gen -sC $(DIR_LIBX_LNX)

#
#common compilation

$(PRINTF_NAME):$(PRINTF)
	cp -p $(PRINTF) $(PRINTF_NAME)

$(PRINTF):
	make -C $(DIR_PRINTF) bonus



print:
	@echo $(DIR_SRC)
	@echo $(SRCS_MAN)
	@echo $(OBJS_MAN)
	@echo $(DPNS_MAN)
	@echo $(INCLUDE)
	@echo $(PRINTF_NAME)
	@echo $(DIR_PRINTF)
	@echo $(PRINTF)
	@echo $(LIBX_NAME)
	@echo $(DIR_LIBX)
	@echo $(LIBX)
	@echo $(LIBX_LNX)
	@echo $(DIR_LIBX_LNX)
	@echo $(LIBX_NAME_LNX)

clean:
	$(RM) $(OBJDST_DIR) $(OBJDST_DIR_LNX)
	make -C$(DIR_PRINTF) clean
	make -C$(DIR_LIBX) clean

fclean:
	make -C$(DIR_PRINTF) fclean
	make -C$(DIR_LIBX) clean
	$(RM) $(PRINTF_NAME) $(NAME) $(NAME_LNX) $(LIBX_NAME) $(LIBX_NAME_LNX)

re: fclean all

.PHONY: all bonus clean fclean re $(PRINTF) $(LIBX_NAME) $(LIBX_LNX)