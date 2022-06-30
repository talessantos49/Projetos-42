/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:22:09 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 05:07:26 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>

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

#endif