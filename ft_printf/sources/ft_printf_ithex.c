/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ithex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:56:47 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 04:54:57 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*new_alocation(int len)
{
	char	*buffer;

	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

long int	ft_dec_to_hex(unsigned int dec, int total, char *hex_adress)
{
	char		*hex;
	long int	len;
	long int	remainder;

	if (dec == 0)
		return (write(1, "0", 1));
	len = ft_len_hex(dec);
	total = len;
	hex = new_alocation(len);
	hex[len--] = '\0';
	while (dec != 0)
	{
		if (dec < 16)
			hex[len--] = hex_adress[dec];
		else
		{
			remainder = dec % 16;
			hex[len--] = hex_adress[remainder];
		}
		dec = dec / 16;
	}
	write(1, hex, total);
	free(hex);
	return (total);
}

int	ft_dec_to_hex_ptr(unsigned long long int dec, int total, char *hex_adress)
{
	char		*hex;
	long int	len;
	long int	remainder;

	if (dec == 0)
		return (write(1, "0", 1));
	len = ft_len_hex(dec);
	total = len;
	hex = new_alocation(len);
	hex[len--] = '\0';
	while (dec != 0)
	{
		if (dec < 16)
			hex[len--] = hex_adress[dec];
		else
		{
			remainder = dec % 16;
			hex[len--] = hex_adress[remainder];
		}
		dec = dec / 16;
	}
	write(1, hex, total);
	free(hex);
	return (total);
}
