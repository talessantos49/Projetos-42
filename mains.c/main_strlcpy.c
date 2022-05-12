/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:16:05 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 16:21:26 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
//size_t	ft_strlcpy(char	*dest, const char	*src, size_t size);

int	main(void)
{
	char src[] = "Hello there, Venus";
	char dest[10];
	unsigned int size = 5;
	
	printf("O valor contido em dest e: %s\n", dest);	
	printf("Os dados sao: %ld\n", ft_strlcpy(dest, src, size));
	printf("O valor contido em dest e: %s\n", dest);
}
