NAME := tests

SRC := $(NAME) Account

CLAS := Account

INC := $(NAME) colors

DIRSRC := ./src/

DIRINC := inc/

OBJDST_DIR := ./objdst_dir/

SRCS := $(addprefix $(DIRSRC), $(addsuffix .cpp,$(SRC)))
OBJS := $(addprefix $(OBJDST_DIR), $(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(OBJDST_DIR), $(addsuffix .d,$(SRC)))
INCS := $(addprefix $(DIRINC), $(addsuffix .h,$(INC)))
CLASS := $(addprefix $(DIRINC), $(addsuffix .hpp,$(CLAS)))

RM := rm -rfd

CC:= g++

FLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME) Makefile

-include:$(sources:.c=.d)

$(NAME): $(DSTS) $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDST_DIR)%.o: $(DIRSRC)%.cpp $(INCS) $(CLASS)
	mkdir -p $(OBJDST_DIR)
	$(CC) $(FLAGS) -c $(DIRSRC)$*.cpp -o $(OBJDST_DIR)$*.o 

$(OBJDST_DIR)%.d: $(DIRSRC)%.cpp
	mkdir -p $(OBJDST_DIR)
	@set -e; rm -f $@; \
	$(CC) -M $(FLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

print:
	@echo NAME: $(NAME)
	@echo SRCS: $(SRCS)
	@echo INCS: $(INCS)
	@echo OBJS: $(OBJS)
	@echo DSTS: $(DSTS)
	@echo OBJDST_DIR: $(OBJDST_DIR)
	@echo DIRSRC: $(DIRSRC)
	@echo DIRINC: $(DIRINC)


clean:
	$(RM) $(OBJDST_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re print