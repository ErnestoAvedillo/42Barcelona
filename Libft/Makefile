NAME = test

SRC = ft_isalpha

HEAD = libft

CFLAGS = -Wall -Werror -Wextra

FOLDER = Libft

TARGET_OBJ = ./$(addsuffix .o, $(NAME))
TARGET_SRC = ./$(addsuffix .c, $(NAME))

OBJS = $(addprefix ./$(FOLDER)/,$(addsuffix .o, $(SRC)))

SRCS = $(addprefix ./$(FOLDER)/,$(addsuffix .c, $(SRC)))

HEADS = $(addprefix ./$(FOLDER)/,$(addsuffix .h, $(HEAD)))

CC = gcc

print:
	@echo $(OBJS) $(TARGET_OBJ)
	@echo $(SRCS) $(TARGET_SRC)
	@echo $(HEADS)
	@ls ./$(FOLDER)/
	@cat $(OBJS)


all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c ./$< -o ./$@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)


.PHONY:		all print 