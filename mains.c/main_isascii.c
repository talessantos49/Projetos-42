/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:06:21 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 15:09:51 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isascii(int c);

int	main ()
{
	char c;
	
	c = 'a';
	printf ("O valor é de um caractere da tabela ascii : %d\n", isascii(c));

	c = 128;
	printf ("O valor não é da tabela ascii: %d\n", isascii(c));
	
	return (0);
}
