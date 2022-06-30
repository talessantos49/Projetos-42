/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:49:14 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/28 05:39:44 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_len_hex( unsigned long int nbr)
{
	int	len;

	len = 0;
	if (!nbr)
		return (0);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
