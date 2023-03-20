/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:37:59 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:51:29 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 1
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>


int				ft_atoi(const char *str);
void			ft_bzero(void *dest, size_t num);
void			*ft_calloc(size_t nitens, size_t tamanho);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *string, const char *stringB, size_t i);
void			*ft_memset(void *dest, int c, size_t n);
void			*ft_memchr(const void *src, int c, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t num);
int				ft_memcmp(const void *src, const void *dest, size_t num);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strnstr(const char *large, const char *small, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *src);
char			*new_alocation(int len);
long long int	ft_len_hex(unsigned long int nbr);
int				ft_dec_to_hex_ptr(unsigned long long int dec,
					int total, char *hex_adress);
int				ft_print_pointer(unsigned long int hex);
int				ft_uitoa(unsigned int n);
long long int	ft_print_i_d(int n);
size_t			ft_uitoa_len(unsigned int n);
long long int	ft_putstr(char *s);
int				ft_putchar(char c);
void			ft_putstr_itoa(char	*str);
long int		ft_dec_to_hex(unsigned int dec, int total, char *hex_adress);
int				ft_printf(const char *str_input, ...);
size_t			ft_strlen(const char *c);
char			*ft_strjoin_gnl(char	*string1, const char	*string2);
char			*ft_strchr(const char *string, int c);
char			*get_line(char	*str);
char			*get_other(char	*str);
char			*new_alocation_buffer(void);
char			*get_next_line(int fd);

#endif