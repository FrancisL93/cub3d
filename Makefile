## ************************************************************************** ##
##                               Variables                                    ##
## ************************************************************************** ##

NAME	= cub3d

EXECUTION = ./$(NAME) map.cub

SRC =   map_validation.c \
		game.c \
		print.c \
		free.c \
		main.c

O = obj/
I = inc/

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I$I

OBJ = $(SRC:%=$O%.o)

RM = /bin/rm -f
RMDIR = /bin/rm -rf

## ************************************************************************** ##
##                               Compilation                                  ##
## ************************************************************************** ##

all: $(NAME)

$O: #Create obj directory
	@mkdir $@
	@echo "\033[0;32mGenerating objects...\033[0m"

$(OBJ): | $O

$(OBJ): $O%.o: % #Build objects $< take the name on the right of ":", $@ take the name on the left of ":"
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) #Libft will compile only once, use "make libft" to recompile
	@echo "\033[0;32mCompiling...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32m$(EX)\033[0;32m compiled! Execute as: $(EXECUTION)\033[0m"

## ************************************************************************** ##
##                                 Cleaning                                   ##
## ************************************************************************** ##

cleanobj: #Delete .o files in obj directory
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj #Delete obj directory
	@$(RMDIR) $O

clean: cleanobjdir #Delete obj directory and content
	@echo "\033[0;31mObjects deleted!\033[0m"

fclean: clean #Delete objects and executable
	@$(RM) $(NAME)
	@$(RM) .DS_STORE
	@$(RMDIR) $(NAME).dSYM
	@echo "\033[1;31m$(EX)\033[0;31m executable deleted!\033[0m"

re: fclean #Delete all and rebuild executable
	@make

## ************************************************************************** ##
##                               Execution                                    ##
## ************************************************************************** ##

MAP = map/good_map.cub
#MAP = map/good_map.txt
#MAP = map/map.cub

exe: $(NAME) #Execute program
	@./$(NAME) $(MAP)

exe-leak: $(NAME)
	@valgrind --leak-check=full --track-origins=yes \
	./$(NAME) $(MAP)
#	--show-leak-kinds=all
#	--trace-children=yes

segfault: $(OBJ)
	@$(CC) $(CFLAGS) -fsanitize=address $(OBJ) -o $(NAME)
#-fsanitize=threads (compiler les objets aussi avec)

debug: $(OBJ) #Compile for debugger
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m$(NAME) compiled! Execute as: $(EXECUTION)\033[0m"

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
