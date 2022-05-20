/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:38:43 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 15:52:01 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void test_func(unsigned int i, char *str)
{
	printf("\nO striteri acontecendo: %d	: %s", i, str);
}
int	main()
{
	char teste[] = "Tesla Motors";
	printf("\nA entrada é: %s\n", teste);
	ft_striteri(teste, test_func);
	printf("\nA saida é: %s\n", teste);
	return 0;
}