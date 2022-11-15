# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malord <malord@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:18:03 by flahoud           #+#    #+#              #
#    Updated: 2022/11/15 09:43:36 by malord           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	src/add_string_first.c		\
		src/add_string_last.c		\
		src/free_double_array.c		\
		src/ft_atoi.c 				\
		src/ft_atol.c				\
		src/ft_bzero.c				\
		src/ft_calloc.c 			\
		src/ft_isalnum.c 			\
		src/ft_isalpha.c 			\
		src/ft_isascii.c 			\
		src/ft_isdigit.c 			\
		src/ft_isprint.c			\
		src/ft_itoa.c 				\
		src/ft_itox.c 				\
		src/ft_linelen.c			\
		src/ft_memchr.c 			\
		src/ft_memcmp.c 			\
		src/ft_memcpy.c 			\
		src/ft_memmove.c 			\
		src/ft_memset.c 			\
		src/ft_ptoa.c 				\
		src/ft_putchar_fd.c 		\
		src/ft_putendl_fd.c 		\
		src/ft_putnbr_fd.c 			\
		src/ft_putstr_fd.c 			\
		src/ft_split.c 				\
		src/ft_strchr.c 			\
		src/ft_strdup.c 			\
		src/ft_striteri.c 			\
		src/ft_strjoin.c 			\
		src/ft_strjoin_free.c 		\
		src/ft_strlcat.c 			\
		src/ft_strlcpy.c 			\
		src/ft_strlen.c 			\
		src/ft_strlen_before.c 		\
		src/ft_strlen_until.c		\
		src/ft_strmapi.c 			\
		src/ft_strncmp.c 			\
		src/ft_strnstr.c 			\
		src/ft_strrchr.c 			\
		src/ft_strtrim.c 			\
		src/ft_strtrim_free.c 		\
		src/ft_substr.c 			\
		src/ft_swap.c 				\
		src/ft_tolower.c 			\
		src/ft_toupper.c 			\
		src/ft_utoa.c 				\
		src/ft_printf.c 			\
		src/ft_lstnew.c 			\
		src/ft_lstadd_front.c 		\
		src/ft_lstsize.c 			\
		src/ft_lstlast.c 			\
		src/ft_lstadd_back.c 		\
		src/ft_lstdelone.c 			\
		src/ft_lstclear.c 			\
		src/ft_lstiter.c 			\
		src/ft_lstmap.c 			\
		src/get_next_line.c			\
		src/int_realloc.c 			\
		src/join_free_both			\
		src/sort_int_tab.c 			\
		src/strcdup.c 				\
		src/strjoin_free_last.c		\
		src/strpop.c 				\
		src/xfree.c					

S = src/
O = obj/
I = inc/

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I$I
LDFLAGS +=

OBJ = $(SRC:$S%=$O%.o)

RM = /bin/rm -f
RMDIR = /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)
	

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PRINTCOMPILE) $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	
cleanobj:
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@$(RMDIR) $O

clean: $O cleanobjdir

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re
