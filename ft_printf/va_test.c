/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:55:52 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 05:15:29 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	soma_int(int n, ...)
{
	va_list	lista;
	int	i, s = 0;
	va_start(lista, n);
	for(i = 1; i <= n; i++)
		s = s + va_arg(lista, int);
	va_end(lista);
	return s;
}

int	main()
{
	int soma;
	soma = soma_int(3, 1, 2, 50, 4,5);
	printf("Soma %i valores : %d\n", 5, soma);
}
