ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME	= cub3d
BONUS	= $(NAME)_bonus

ARG = maps/good_map.cub
ARG_BONUS = maps/good_map_bonus.cub
#ARG = maps/good_map.txt
#ARG = maps/map.cub

TEST = maps/error_start.cub maps/error_wall.cub maps/good_map.txt maps/error_2start.cub \
		maps/map.cub maps/good_map.txt maps/error_textures.cub maps/error_config.cub maps/good_map_bonus.cub

SRCS = 	assets.c			\
		bonus_tools.c		\
		doors.c				\
		floor_casting.c		\
		init_data.c 		\
		game_tools.c		\
		keys.c				\
		launcher.c 			\
		map.c 				\
		map_info.c 			\
		map_parsing.c		\
		map_tools.c			\
		print.c 			\
		print_tools.c		\
		quit_game.c			\
		raycasting.c		

SRC := $(SRCS)
SRC += main.c
SRC_BONUS := $(SRCS)
SRC_BONUS += main_bonus.c start_screen.c keysbonus.c

LDFLAGS	+= -framework OpenGL -framework AppKit
LIBS 	= $(LIBFTA) $(MLXA)

LIBFT = include/libft
LIBFTA = include/libft/libft.a

MLX = include/mlx
MLXA = include/mlx/libmlx.a

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##
all: $(NAME)

test: $(TEST)
	@$(foreach file,$(TEST),leaks --atExit -- ./$(NAME) $(file);)

test-bonus: $(TEST)
	@$(foreach file,$(TEST), ./$(BONUS) $(file);)

$(LIBFTA):
	@echo "\033[0;32mCompiling libft...\033[0m"
	@make -C $(LIBFT)
	@make clean -C $(LIBFT)
	@echo "\033[0;32mLibft compiled!\n\033[0m"

$(MLXA):
	@echo "\033[0;32mCompiling mlx...\033[0m"
	@make -C $(MLX)
	@echo "\033[0;32mMlx compiled!\n\033[0m"

endif