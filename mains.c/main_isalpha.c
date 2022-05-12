/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:17:35 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 14:22:47 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isalpha(int c);

int	main()
{
	char c;
	c = 'I';
	printf("Letra maiuscula presente no alfabeto retorna: %d\n", isalpha(c));

	c = 'i';
	printf("Letra minuscula presente no alfabeto retorna: %d\n", isalpha(c));

	c = ',';
	printf("Caractere não presente no alfabeto retorno: %d\n", isalpha(c));

	return (0);
}
