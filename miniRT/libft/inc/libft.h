/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:01:53 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/20 22:33:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

//**************** LIBFT FUNCTIONS *******************//

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

//************* LINKED LIST ************************//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

/* Extra	*/

int				ft_array_size(char **array);
char			**ft_array_free(char **Array, int len);
char			*ft_substr_free(char const *s, unsigned int start,
					size_t len, int one_if_free_s);

char			*ft_strlwr(char *str);
char			*ft_strjoinfree(char *s1, char *s2);
void			ft_putstr(char *str);
long			ft_atol(const char *str);
int				ft_isnumeric(char *str);
long long		ft_atoll(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_isstralnum(char *str);
int				ft_isupper(int c);
int				ft_isstrupper(char *str);
int				ft_isstrprint(char *str);
char			*ft_strpbrk(const char *s, const char *charset);
int				ft_isspace(int c);
int				ft_isstrspace(char *str);
int				ft_isallspace(char *str);
int				ft_isallalpha(char *str);
bool			ft_isstrarray(char *str, char **array);

char			*get_next_line(int fd);
void			ft_print_array(char **array);
double			ft_atof(const char *str);
char			**ft_split_spaces(char const *s);

int				ft_check_extension(char *filename, char *ext);

#endif