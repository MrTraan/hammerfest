NAME = hammerfest.out

CPP_DIR = src
CPP_DIRS = $(shell find $(CPP_DIR) -type d -follow -print | grep -v '/tests_')
CPP_FILES = $(shell find $(CPP_DIRS) -type f -follow -print | grep "\.cpp" | grep -v '.swp')

O_DIR =	.tmp/obj
O_DIRS = $(CPP_DIRS:$(CPP_DIR)%=$(O_DIR)%)
O_FILES = $(CPP_FILES:$(CPP_DIR)%.cpp=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes
LIB = -framework SFML -framework sfml-window -framework sfml-graphics -framework sfml-system -framework sfml-audio

CC = g++ -std=c++11

all: $(NAME)

$(NAME): $(O_FILES)
	echo $^
	$(CC) $(FLAGS) $^ $(INCLUDES) $(LIB) -o $@

$(O_DIR)%.o: $(CPP_DIR)%.cpp
	@mkdir -p $(O_DIRS) $(O_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -Rf $(O_DIR)

fclean: clean
	@rm $(NAME) || true
	@rm -Rf .tmp/

re: fclean all

.PHONY: clean all fclean re
