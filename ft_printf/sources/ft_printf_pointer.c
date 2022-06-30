/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:16:55 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 04:56:50 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
unsigned long int	ft_print_pointer(char	*str)
{
	unsigned long int	t;

	t = (unsigned long int)str;
	if (!str)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_dec_to_hex(t, 0, "0123456789abcdef") + 2);
}
*/

int	ft_print_pointer(unsigned long int hex)
{
	unsigned long int	t;

	t = hex;
	if (hex == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_dec_to_hex_ptr(t, 0, "0123456789abcdef") + 2);
}
