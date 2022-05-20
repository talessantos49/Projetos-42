/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:26:43 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/06 17:37:06 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *c);

int	main()
{
	char c[] = "Ratos correndo uma corrida Longa";

	printf("O tamanho da palavra pela funcao é: %li \n", ft_strlen(c));
	printf("O tamanho da palavra pela funcao é: %li \n", strlen(c));

	return (0);
}
