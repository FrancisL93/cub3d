ifndef SETTINGS_MK
 SETTINGS_MK = 1

## ************************************************************************** ##
##                             Project Variables                              ##
## ************************************************************************** ##

NAME	= cub3d
BONUS	= $(NAME)_bonus

ARG = maps/good_map_bonus.cub
#ARG = maps/good_map.txt
#ARG = maps/map.cub

SRCS = 	map.c 				\
		map_info.c 			\
		assets.c			\
		map_tools.c			\
		game_tools.c		\
		print.c 			\
		print_tools.c		\
		game.c				\
		floor_casting.c		\
		free.c 				\
		map_parsing.c		\
		data.c 				\
		raycasting.c		\
		raycasting_tools.c  \
		minimap.c			\
		mouse_move.c		\
		parsing_bonus.c

SRC := $(SRCS)
SRC += main.c
SRC_BONUS := $(SRCS)
SRC_BONUS += main_bonus.c

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