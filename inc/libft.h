/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:14:34 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/23 14:58:54 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

typedef struct s_list
{	
	struct s_list	*prev;
	int				content;
	size_t			index;
	char			id;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str);

int			ft_isascii(int c);

int			ft_isdigit(int c);

char		*ft_itoa(int n);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		*ft_memset(void *b, int c, size_t len);

int			ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

int		ft_putstr_fd(char *s, int fd);

char		**ft_split(char const *s, char c);

char		*ft_strdup(const char *s1);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);

size_t		ft_strlen(const char *s);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int c);

int			ft_toupper(int c);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_lstadd_front(t_list **alst, t_list *new);

int			ft_lstadd_back(t_list **start, t_list **new_node, size_t index);

void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void *));

int			ft_lstsize(t_list *lst);

#endif