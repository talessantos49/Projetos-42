/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:28:33 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 14:31:03 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isdigit(int c);

int	main()
{
	char	c;
	c = '7';
	printf("Caractere numerico : %d\n", isdigit(c));

	c = '=';
	printf("Caractere não numerico : %d\n", isdigit(c));

	return (0);
}