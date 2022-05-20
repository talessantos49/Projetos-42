/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:35:20 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/05 18:33:43 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	toupper(int c);

int	main()
{
	char	c;

	c = 'f';
	printf(" %c\n", toupper(c));

	c = '@';
	printf(" %c\n", toupper(c));

	c = '+';
	printf(" %c\n", toupper(c));
	
	return (0);
}
