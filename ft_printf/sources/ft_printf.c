/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:28:31 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/28 06:03:35 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_verification(char c, va_list arg)
{
	int	count_char;

	count_char = 0;
	if (c == 'c')
		count_char += ft_putchar(va_arg(arg, int));
	if (c == 's')
		count_char += ft_putstr(va_arg(arg, char *));
	if (c == '%')
		count_char += ft_putchar('%');
	if (c == 'i' || c == 'd')
		count_char += ft_print_i_d(va_arg(arg, int));
	if (c == 'u')
		count_char += ft_uitoa(va_arg(arg, int));
	if (c == 'x')
		count_char += ft_dec_to_hex(va_arg(arg, int), 0, "0123456789abcdef");
	if (c == 'X')
		count_char += ft_dec_to_hex(va_arg(arg, int), 0, "0123456789ABCDEF");
	if (c == 'p')
		count_char += ft_print_pointer(va_arg(arg, unsigned long int));
	return (count_char);
}

int	ft_printf(const char *str_input, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str_input)
		return (-1);
	va_start(arg, str_input);
	while (str_input[i])
	{
		if (str_input[i] == '%')
			count += ft_verification(str_input[++i], arg);
		else
		{
			ft_putchar(str_input[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
