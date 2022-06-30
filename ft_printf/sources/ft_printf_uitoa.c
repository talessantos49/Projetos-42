/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:57:40 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 05:01:55 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_uitoa_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;
	int		total;

	len = ft_uitoa_len(n);
	total = ft_uitoa_len(n);
	if (n == 0)
		return (write(1, "0", 1));
	str = malloc(len + 1);
	if (!str)
		return ('\0');
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	ft_putstr(str);
	free(str);
	return (total);
}
