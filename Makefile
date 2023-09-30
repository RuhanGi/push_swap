SRCS =  ./psrc/push_swap.c ./psrc/sort.c ./psrc/median.c ./psrc/extract.c \
		./start/initiate.c ./start/parse.c \
		./moves/moves.c ./moves/moves2.c \
		./utils/func.c ./utils/ft_split.c \
		./utils/get_next_line_utils.c \

C_SRCS = ./csrc/c_checker.c \
		 ./start/initiate.c ./start/parse.c \
		 ./moves/moves.c ./moves/moves2.c \
		 ./utils/func.c ./utils/ft_split.c \
		 ./utils/get_next_line.c ./utils/get_next_line_utils.c \

FLAGS = -Wall -Werror -Wextra

NAME = push_swap

C_NAME = checker

all: $(NAME) bonus

$(NAME):
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

$(C_NAME):
	@gcc $(FLAGS) $(C_SRCS) -o $(C_NAME)

bonus: $(C_NAME)

vis: re
	@/usr/bin/python3 ./python_visualizer.py `ruby -e "puts (1..30).to_a.shuffle.join(' ')"`

clean:

fclean: clean
	@rm -f $(NAME) $(C_NAME)

re: fclean all
