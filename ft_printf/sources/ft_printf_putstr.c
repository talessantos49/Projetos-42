/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:37 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/28 05:05:25 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long long int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (i);
}

long long int	ft_print_i_d(int n)
{
	char	*str;
	int		size;

	str = ft_itoa(n);
	size = ft_putstr(str);
	free (str);
	return (size);
}
