/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:36:39 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 14:39:44 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isalnum(int c);

int	main()
{
	char c;
	
	c = '1';
	printf("Valor de caractere numerico : %d\n", isalnum(c));

	c = 'G';
	printf("Valor de caractere maisculo: %d\n",isalnum(c));

	c = 'k';
	printf("Valor de caractere minusculo: %d\n", isalnum(c));

	c = '+';
	printf("Valor de caractere não numerico e não alpha: %d\n", isalnum(c));

	return (0);
}
