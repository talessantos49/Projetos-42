/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:17:07 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 01:10:59 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h> //-lbsd	

char	*ft_strnstr(char	*large, char	*small, size_t n);

int	main(void)
{
	char *largestring = "aaabcabcd";
	char *smallstring = "abcd";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 9);
	printf("O retorno é: %s\n", ptr);
}