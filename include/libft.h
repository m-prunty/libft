/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:42:32 by mprunty           #+#    #+#             */
/*   Updated: 2025/01/13 05:07:48 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

# ifndef STRUCT_T_LIST
#  define STRUCT_T_LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
# endif

// ../lib/ft/c_std/
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(char c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
int		ft_isupper(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, int num);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str );
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// ../lib/ft/c_ext/
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, size_t start, size_t len);

// ../lib/ft/bonus/
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new_ele);
void	ft_lstadd_front(t_list **lst, t_list *new_ele);
void	ft_lstadd_front(t_list **lst, t_list *new_ele);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
int		ft_lstsize(t_list *lst);

// ../lib/ft/printf/
int		ft_atoi_base(const char *nptr, int base);
int		ft_iputchar(int c);
int		ft_iputnum(long long n, int base, int caps);
int		ft_iputnum_ptr(size_t n);
int		ft_iputptr(size_t argp);
int		ft_iputstr(char *str);
int		ft_printf(const char *format, ...);

// ../lib/ft/gnl/
char	*get_next_line(int fd);

// ../lib/ft/ext/
int		ft_isnum(char *str);
int		ft_isnumf(char *str);
int		ft_isnumi(char *str);

// ../lib/ft/c_ext/
long	ft_atol(const char *nptr);
long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
#endif
