/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:13:43 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/13 06:55:42 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const	*src, unsigned int	start, size_t	len);

int	main(void)
{
	char	entrada[] = "A substring inicia no u";

	printf("A resposta obtida foi: %s\n", ft_substr(entrada, 0, 0));	
}
