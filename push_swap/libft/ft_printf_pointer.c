/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:16:55 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:55:15 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(unsigned long int hex)
{
	unsigned long int	t;

	t = hex;
	if (hex == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_dec_to_hex_ptr(t, 0, "0123456789abcdef") + 2);
}
