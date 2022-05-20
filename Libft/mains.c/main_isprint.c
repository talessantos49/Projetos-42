/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:04 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 14:56:39 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isprint(int c);

int	main()
{
	char c;
	
	c = ' '; //imprimível
	printf("%d \n", isprint(c));

	c = '4'; //imprimivel
	printf("%d\n", isprint(c));

	c = '	'; //não imprimivel
	printf("%d\n", isprint(c));

	c = '\n'; // não imprimivel
	printf("%d\n", isprint(c));

	return (0);
}
