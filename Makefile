## ************************************************************************** ##
##                               Variables                                    ##
## ************************************************************************** ##

NAME	= cub3d
EXECUTION = ./$(NAME) map.cub

SRC =   map_validation.c 	\
		map.c 				\
		map_info.c 			\
		assets.c			\
		map_tools.c			\
		game.c 				\
		game_tools.c		\
		print.c 			\
		print_tools.c		\
		free.c 				\
		main.c				\
		map_parsing.c		\
		raycasting.c

LIBFT = include/libft
LIBFTA = include/libft/libft.a

MLX = include/minilibx
MLXA = include/minilibx/libmlx.a
#MLX = mlx/ (M1 Mac @home)
#MLXA = mlx/libmlx.a (M1 Mac @home)

O = obj/
S = src/
I = inc/

CC = gcc -g
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I$I

OBJ = $(SRC:%=$O%.o)

RM = /bin/rm -f
RMDIR = /bin/rm -rf

## ************************************************************************** ##
##                             Pre-Compilation                                ##
## ************************************************************************** ##

## ************************************************************************** ##
##                               Compilation                                  ##
## ************************************************************************** ##

all: $(NAME)

$O: #Create obj directory
	@mkdir $@
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"

$(OBJ): | $O

$(OBJ): $O%.o: $S% #Build objects $< take the name on the right of ":", $@ take the name on the left of ":"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTA):
	@echo "\033[0;32mCompiling libft...\033[0m"
	@make -C $(LIBFT)
	@make clean -C $(LIBFT)
	@echo "\033[0;32mLibft compiled!\n\033[0m"

$(MLXA):
	@echo "\033[0;32mCompiling mlx...\033[0m"
	@make -C $(MLX)
	@echo "\033[0;32mMlx compiled!\n\033[0m"

$(NAME): $(MLXA) $(LIBFTA) $(OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFTA) $(OBJ) -o $(NAME)
	@echo "\033[0;32mCompiled! Execute as: $(EXECUTION)\033[0m"

## ************************************************************************** ##
##                                 Cleaning                                   ##
## ************************************************************************** ##

cleanmlx:
	@$(RM) $(MLXA)

cleanobj: #Delete .o files in obj directory
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj #Delete obj directory
	@$(RMDIR) $O

clean: cleanobjdir #Delete obj directory and content
	@echo "\033[0;31mObjects deleted!\033[0m"

fclean: clean #Delete objects and executable
	@$(RM) $(LIBFTA)
	@echo "\033[0;31mLibft.a deleted!\033[0m"
	@$(RM) $(NAME)
	@echo "\033[0;31mExecutable deleted!\033[0m"

re: fclean #Delete all and rebuild executable
	@make

## ************************************************************************** ##
##                               Execution                                    ##
## ************************************************************************** ##

MAP = maps/good_map.cub
#MAP = maps/good_map.txt
#MAP = maps/map.cub

exe: $(NAME) #Execute program
	@./$(NAME) $(MAP)

exe-leak: $(NAME)
	@leaks --atExit -- ./$(NAME) $(MAP)
#	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(MAP)
#	--trace-children=yes

segfault: $(MLXA) $(LIBFTA) $(OBJ)
	@$(CC) $(CFLAGS) $(MLXA) $(LIBFTA) -fsanitize=address -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@echo "\033[0;32mCompiled with segfault flag! Execute as: $(EXECUTION)\033[0m"
#-fsanitize=threads (compiler les objets aussi avec)

debug: $(LIBFTA) $(OBJ) #Compile for debugger
	@$(CC) $(CFLAGS) $(LIBFTA) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@echo "\033[0;32mCompiled with -g for debug! Execute as: $(EXECUTION)\033[0m"

list: 	#Show all make rules
	@grep '^[^#[:space:]].*:' Makefile

.PHONY: all clean fclean re

#Color Codes
#RESET		\e[0m
#BLACK		\e[1;30m
#RED		\e[1;31m
#GREEN		\e[1;32m
#YELLOW		\e[1;33m
#BLUE		\e[1;34m
#MAGENTA	\e[1;35m
#CYAN		\e[1;36m
#WHITE		\e[1;37m
