# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malord <malord@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 09:39:10 by malord            #+#    #+#              #
#    Updated: 2022/10/20 20:39:33 by malord           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
OBJDIR		=	bin/
SRCDIR		=	src/

SRCS		=	src/add_string_first.c		\
				src/add_string_last.c		\
				src/free_double_array.c		\
				src/ft_atoi.c				\
				src/ft_atol.c				\
				src/ft_bzero.c				\
				src/ft_calloc.c				\
				src/ft_free.c				\
				src/ft_isalnum.c			\
				src/ft_isalpha.c			\
				src/ft_isascii.c			\
				src/ft_isdigit.c			\
				src/ft_isprint.c			\
				src/ft_isspace.c			\
				src/ft_itoa.c				\
				src/ft_itox.c				\
				src/ft_linelen.c			\
				src/ft_lstlast.c			\
				src/ft_lstadd_back.c		\
				src/ft_lstadd_front.c		\
				src/ft_lstclear.c			\
				src/ft_lstdelone.c			\
				src/ft_lstnew.c				\
				src/ft_lstiter.c			\
				src/ft_lstmap.c				\
				src/ft_lstsize.c			\
				src/ft_memchr.c				\
				src/ft_memcmp.c				\
				src/ft_memcpy.c				\
				src/ft_memmove.c			\
				src/ft_memset.c				\
				src/ft_numlen_base.c		\
				src/ft_ptoa.c				\
				src/ft_putchar_fd.c			\
				src/ft_putendl_fd.c			\
				src/ft_putnbr_fd.c			\
				src/ft_putstr_fd.c			\
				src/ft_split.c				\
				src/ft_strchr.c				\
				src/ft_strdup.c				\
				src/ft_striteri.c			\
				src/ft_strjoin.c			\
				src/ft_strjoin_free.c		\
				src/ft_strlcat.c			\
				src/ft_strlcpy.c			\
				src/ft_strlen.c				\
				src/ft_strlen_before.c		\
				src/ft_strlen_until.c		\
				src/ft_strmapi.c			\
				src/ft_strncmp.c			\
				src/ft_strncpy.c			\
				src/ft_strndup.c			\
				src/ft_strnstr.c			\
				src/ft_strrchr.c			\
				src/ft_strtrim.c			\
				src/ft_strtrim_free.c		\
				src/ft_substr.c				\
				src/ft_swap.c				\
				src/ft_tolower.c			\
				src/ft_toupper.c			\
				src/ft_utoa.c				\
				src/get_next_line.c			\
				src/int_realloc.c			\
				src/join_free_both.c		\
				src/sort_int_tab.c			\
				src/strcdup.c				\
				src/strjoin_free_first.c	\
				src/strjoin_free_last.c		\
				src/strpop.c				\
				src/xfree.c

OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Targets

#.c.o:
#				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME): $(OBJS)
				@ar -crs $(NAME) $(OBJS)
				
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(OBJDIR)
		@$(CC) $(CFLAGS) -c $< -o $@	

$(OBJDIR):
				@mkdir -p $(OBJDIR)

# Removes objects
clean:
				@$(RM) $(OBJS)

# Removes objects and executable
fclean: 		clean
				@$(RM) $(NAME)

# Removes objects and executable then remakes all
re: 			fclean all
				
.PHONY:			all clean fclean bonus re				