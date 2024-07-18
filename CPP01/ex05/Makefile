NAME = harl
SRC = main.cpp Harl.cpp
OBJS_DIR = objs/
OBJ = $(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))
CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
COMPILER = $(CPP) $(CFLAGS)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	$(COMPILER) $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	@echo "Compiling $<"
	@mkdir -p $(OBJS_DIR)
	$(COMPILER) -c $< -o $@

clean:
	$(RM) $(OBJ)
	rmdir objs/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
