/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:07:18 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/24 15:54:45 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define DEF_LL			long long
# define DEF_L			long
# define DEF_ULL		unsigned long long
# define DEF_UL			unsigned long
# define DEF_UI			unsigned int
# define DEF_US			unsigned short
# define DEF_S			short
# define DEF_UCHAR		unsigned char

# define NEW(T)	((T*)ft_malloc(sizeof(T), __func__, ": Malloc failed " #T));

# include <string.h>
# include <limits.h>
# include <wchar.h>

typedef DEF_LL				t_ll;
typedef DEF_L				t_l;
typedef DEF_ULL				t_ull;
typedef DEF_UL				t_ul;
typedef DEF_UI				t_ui;
typedef DEF_US				t_us;
typedef DEF_S				t_s;
typedef DEF_UCHAR			t_uchar;

typedef struct s_list		t_list;
typedef union u_nbr_union	t_u_nbr;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

union		u_nbr_union
{
	wchar_t	wc;
	t_uchar	uc;
	char	c;
	t_us	us;
	t_s		s;
	t_ui	ui;
	int		i;
	t_ul	ul;
	t_l		l;
	t_ull	ull;
	t_ll	ll;
};

void		ft_error(const char *msg);
void		*ft_malloc(size_t size, const char *func, const char *err);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, void const *src, size_t n);
void		*ft_memccpy(void *dst, void const *src, int c, size_t len);
void		*ft_memmove(void *dst, void const *src, size_t len);
void		*ft_memchr(void const *s, int c, size_t n);
int			ft_memcmp(void const *s1, void const *s2, size_t n);
int			*ft_range(int min, int max);
char		*ft_strdup(char const *s1);
char		*ft_strcpy(char *dst, char const *src);
char		*ft_strncpy(char *dst, char const *src, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_wstrlen(const wchar_t *str);
void		ft_putstr(void *str);
void		ft_putnstr(void *str, int len);
void		ft_putn_ustr(void *str, int len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
char		*ft_strtoupper(char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_putnbr(int nbr);
int			ft_putnbr_fd(int nbr, int fd);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
int			ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_put_x_char(char c, int nbr);
void		ft_putstr_fd(char const *s, int fd);
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_stoabase(short nbr, const char *base);
char		*ft_itoabase(int nbr, const char *base);
char		*ft_ltoabase(t_l nbr, const char *base);
char		*ft_ctoabase(char nbr, const char *base);
t_l			ft_l_to_oct(t_l nbr);
char		*ft_wstrto_nstr(wchar_t *w_str, int nbr_bytes);
int			ft_wcharto_str(char **buff, int pos, wchar_t w_c);
int			ft_isblank(int c);
int			ft_isinvisible(int c);
void		ft_foreach(int *tab, int lenght, void (*f)(int));
int			ft_count_if(char **tab, int (*f)(char*));
int			ft_min(int a, int b);
int			ft_max(int a, int b);
t_ll		ft_abs(t_ll num);
size_t		ft_intlen(int nbr);
size_t		ft_lintlen(long nbr);
int			ft_llintlen(long long nbr);
size_t		ft_ullintlen(unsigned long long nbr);
int			ft_power(int x, int n);
long long	ft_llpower(long long x, long long n);
int			ft_put_llnbr(long long nbr);
int			ft_put_ullnbr(unsigned long long nbr);

#endif
