# Program name
NAME    = cub3D

# Compiler options
CC      = cc 
CFLAGS  = -Wall -Wextra -Werror -g

DIR_OBJ = obj/

DIR_SRC = src/

# Libft
LIBFT   = libft/libft.a

# MinilibX
LIBMLX  = minilibx-linux/libmlx.a

# Colors
RESET_COLOR = \033[0m
BOLD = \033[1m
GREEN = \033[92m
BLUE = \033[94m

# Cub3D files

SRCS  = src/cub3d.c \
		src/data_init.c \
		src/display_door.c \
		src/display.c \
		src/error_2.c \
		src/error.c \
		src/exit.c \
		src/get_next_line.c \
		src/img_to_create.c \
		src/map_init.c \
		src/minimap.c \
		src/minimap_walls.c \
		src/movements_1.c \
		src/movements_2.c \
		src/raycasting_1.c \
		src/raycasting_2.c \
		src/raycasting_door.c \
		src/texture_init_2.c \
		src/textures_init.c \
		src/utils_1.c \
		src/utils_2.c

OBJ = $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRCS))

# Compiling Libft, Mlx and project
$(NAME): $(OBJ)
		@echo "$(BOLD)$(BLUE)		   _____      _    ____  _____ $(RESET_COLOR)" 
		@echo "$(BOLD)$(BLUE)		  / ____|    | |  |___ \|  __ \ $(RESET_COLOR)"
		@echo "$(BOLD)$(BLUE)		 | |    _   _| |__  __) | |  | |$(RESET_COLOR)"
		@echo "$(BOLD)$(BLUE)		 | |   | | | | '_ \|__ <| |  | |$(RESET_COLOR)"
		@echo "$(BOLD)$(BLUE)		 | |___| |_| | |_) |__) | |__| |$(RESET_COLOR)"
		@echo "$(BOLD)$(BLUE)		  \_____\__,_|_.__/____/|_____/ $(RESET_COLOR)"
		@echo "\n"
		@echo "$(BOLD)$(BLUE)🛠️ 🚧     Compiling Libft...     🚧🛠️$(RESET_COLOR)"
		@make -sC ./libft
		@echo "\n"
		@echo "$(BOLD)$(BLUE)🛠️ 🚧     Compiling MiniLibX...     🚧🛠️$(RESET_COLOR)"
		@make -sC ./minilibx-linux
		@echo "\n"
		@echo "$(BOLD)$(BLUE)🛠️ 🚧     Compiling project...     🚧🛠️$(RESET_COLOR)"
		@echo "\n"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) -lXext -lX11 -lm
		@echo "$(BOLD)$(GREEN)🧊🎮🧟    Cub3D ready to use    🧟🎮🧊$(RESET_COLOR)"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		@echo "$(BOLD)$(BLUE)🧹🧼     Cleaning .o Libft's & MiniLibX's files...     🧼🧹$(RESET_COLOR)"
		@make clean -sC libft
		@make clean -sC minilibx-linux
		@rm -rf $(DIR_OBJ)

fclean: clean
		@rm -rf $(NAME)
		@make fclean -sC libft
		@echo "\n"
		@echo "$(BOLD)$(GREEN)🧹🧼     Cleaning finished     🧼🧹$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus