/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:40:35 by malord            #+#    #+#             */
/*   Updated: 2022/10/25 16:08:27 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 42 School library of functions to be used in projects. 

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// int return values functions

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isdigit(int n);
int		ft_isprint(int n);
int		ft_isspace(char c);
int		ft_linelen(const char *str);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_numlen_base(long nbr, long base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int n);
int		ft_toupper(int n);

// int * return values functions

int		*int_realloc(int *old_array, int old_size, int size);

// void return values functions

void	free_double_array(void **array);
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_swap(int *a, int *b);
void	sort_int_tab(int *tab, unsigned int size);

// void * return values functions

void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*xfree(void *ptr);

// char * return values functions

char	*add_string_first(int c, char *str);
char	*add_string_last(int c, char *str);
char	*ft_free(void *ptr);
char	*ft_itoa(int n);
char	*ft_itox(int nbr);
char	*ft_ptoa(uintptr_t nbr);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strndup(const char *str, int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim_free(char *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_utoa(unsigned int nbr);
char	*get_next_line(int fd);
char	*join_free_both(char *s1, char *s2);
char	*strcdup(char *basestr, char *matchchrs);
char	*strjoin_free_first(char *s1, char *s2);
char	*strjoin_free_last(char *s1, char *s2);
char	*strpop(char *str, int position);

// char ** return values functions

char	**ft_split(char const *str, char c);

// size_t return values functions

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_before(char *s, char *c);
size_t	ft_strlen_until(char *s, char c);

// long return values functions

long	ft_atol(const char *str);

// t_list return values functions

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

#endif
