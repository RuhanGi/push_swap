NAME = push_swap
C_NAME = checker

SRCS = psrc/push_swap.c psrc/sort.c psrc/median.c psrc/extract.c \
	   start/initiate.c start/parse.c \
	   moves/moves.c moves/moves2.c \
	   utils/func.c utils/ft_split.c \
	   utils/get_next_line_utils.c

C_SRCS = csrc/c_checker.c \
		 start/initiate.c start/parse.c \
		 moves/moves.c moves/moves2.c \
		 utils/func.c utils/ft_split.c \
		 utils/get_next_line.c utils/get_next_line_utils.c

OBJ_DIR = obj
SRCDIR = src
C_SRC_DIR = csrc
INC_DIR = includes
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
C_OBJS = $(addprefix $(OBJ_DIR)/, $(C_SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

.SILENT:

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/start
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/psrc
	mkdir -p $(OBJ_DIR)/moves
	mkdir -p $(OBJ_DIR)/csrc
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all: $(NAME) bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\x1B[0m\n"

bonus: $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(C_NAME)
	@printf "\x1B[32m$(C_NAME) ready\x1B[0m\n"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(C_NAME)

re: fclean all

vis: re
	/usr/bin/python3 ./python_visualizer.py `ruby -e "puts (1..30).to_a.shuffle.join(' ')"`
