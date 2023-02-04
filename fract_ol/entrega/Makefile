NAME := fractol

SRC := fractol
DIR_SRC := ./srcs/

OBJDST_DIR := ./objdst/
#source files
SRCS_MAN := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .o,$(SRC)))
DPNS_MAN := $(addprefix $(OBJDST_DIR),$(addsuffix .d,$(SRC)))
INCLUDE := $(addprefix $(DIR_SRC),$(addsuffix .h,$(NAME)))
#libraries
#libft
LIBFT_NAME := libft.a
DIR_LIBFT := ./libft/
LIBFT = $(addprefix $(DIR_LIBFT),$(LIBFT_NAME))
#minilibX
LIBX_NAME := MiniLibX.a
DIR_LIBX := ./libx1/
LIBX = $(addprefix $(DIR_LIBFT),$(LIBFT_NAME))
#link elements
LIBX_LNK := -lmlx -framework OpenGL -framework AppKit 
LIBX_DIR := 
RM := rm -rfd
CC := gcc 
FLAGS := -Wall -Werror -Wextra

all : $(NAME)
	echo "pepirto"

-include:$(DPNS_MAN)

$(NAME): $(OBJS_MAN) $(DPNS_MAN) $(LIBFT_NAME) $(LIBX_NAME)
	$(CC) $(FLAG) -I $(DIR_LIBFT) -I $(DIR_LIBX) $(LIBX_LNK) $(OBJS_MAN) -o $(NAME)

$(OBJDST_DIR)%.o $(OBJDST_DIR)%.d: $(DIR_SRC)%.c $(INCLUDE)
	@echo $*.c
	mkdir -p $(OBJDST_DIR)
	@echo $*.c
	$(CC) $(FLAG) -c $(DIR_SRC)$*.c -o $(OBJDST_DIR)$*.o
	$(CC) -MM $(FLAG) -c $(DIR_SRC)$*.c > $(OBJDST_DIR)$*.d

$(LIBFT_NAME):$(LIBFT)
	cp -p $(LIBFT) $(LIBFT_NAME)

$(LIBFT):
	make -C $(DIR_LIBFT) bonus

$(LIBX_NAME):$(LIBX)
	cp -p $(LIBX) $(LIBX_NAME)

$(LIBX_NAME):
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

clean:
	$(RM) $(OBJDST_DIR)
	make -C&(DIR_LIBFT) clean

fclean:
	make -C&(DIR_LIBFT) fclean
	$(RM) $(LIBFT_NAME) $(NAME)



PHONY: all bonus clean fclean re $(LIBFT) $(LIBX_NAME)