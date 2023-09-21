NAME := megaphone

SRC := $(NAME)

INC := 

DIRSRC := ./

DIRINC := ./

OBJDST_DIR := ./objdst_dir/

SRCS := $(addprefix $(DIRSRC), $(addsuffix .cpp,$(SRC)))
OBJS := $(addprefix $(OBJDST_DIR), $(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(OBJDST_DIR), $(addsuffix .d,$(SRC)))
INCS := $(addprefix $(DIRINC), $(addsuffix .hpp,$(INC)))

RM := rm -rfd

CC:= g++

FLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME) Makefile

-include:$(sources:.c=.d)

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDST_DIR)%.o: $(DIRSRC)%.cpp $(OBJDST_DIR)%.d
	mkdir -p $(OBJDST_DIR)
	$(CC) $(FLAGS) $(INCS) -c $(DIRSRC)$*.cpp -o $(OBJDST_DIR)$*.o 

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