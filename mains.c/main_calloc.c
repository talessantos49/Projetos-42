/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:18:55 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/26 17:42:21 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitens, size_t tamanho);

int	main(void)
{
	int	*p;
	int *d;
	int	a;
	int i;

	a = 5;
	p = (int	*) calloc (a, sizeof(int));
	d = (int	*) ft_calloc (a, sizeof(int));
	printf("O valor de p e: %ls \n", p);
	printf("O valor de d e: %ls \n", d);
	if (!p)
	{
		printf("** Erro: Memoria Insuficiente **");
		return (0);
	}
	if (!d)
	{
		printf("** Erro: Memoria Insuficiente **");
		return (0);
	}
	for (i = 0; i < a; i++)
	{
		printf("\nO Valor de p eh: %i ", p[i]);
		p[i] = i * i;	
	}
	for (i = 0; i < a; i++)
	{
		printf("\nO Valor de d eh: %i ", d[i]);
		d[i] = i * i;	
	}
	return (0);
}
