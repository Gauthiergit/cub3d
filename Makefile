RESET_COLOR = \033[0m
BOLD = \033[1m
GREEN = \033[92m
BLUE = \033[94m


NAME = cub3d

DIR_OBJ = obj/

DIR_SRC = src/

LIBFT = libft/libft.a

LIBMLX = minilibx-linux/libmlx.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRCS = src/cub3d.c \
		src/error.c \
		src/get_next_line.c \

OBJ = $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRCS))

$(NAME): $(OBJ)
		@clear
		@echo "$(BOLD)$(BLUE)Compiling libft...$(RESET_COLOR)"
		make -C ./libft
		@echo "$(BOLD)$(BLUE)Compiling minilibx...$(RESET_COLOR)"
		make -C ./minilibx-linux
		@echo "$(BOLD)$(BLUE)Compiling project...$(RESET_COLOR)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) -lXext -lX11
		@echo "$(BOLD)$(GREEN)Compiling finished$(RESET_COLOR)"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		@echo "$(BOLD)$(BLUE)Cleaning...$(RESET_COLOR)"
		make clean -C libft
		make clean -C minilibx-linux
		rm -rf $(DIR_OBJ)

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft
		@echo "$(BOLD)$(GREEN)Cleaning finished$(RESET_COLOR)"

re: fclean all 