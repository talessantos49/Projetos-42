/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:48:08 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 21:31:53 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_strlcat.c"
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t	size);
size_t	ft_strlen(const char *c);

int	main(void)
{
	char	dest[30]; memset(dest, 0, 30);
	char	src[50] = "Tesla Juncao ";
	unsigned int size = 0;
	
	dest[0] = 'B';
	printf("Entrada : %s\n", dest);
	printf("Os valores retornados sao: %ld\n",ft_strlcat(dest, src, size));
	printf("Saida : %s\n", dest);
}
