/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:39:10 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 05:24:31 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

 char my_func(unsigned int i, char str)
 {
 	printf("Informações da função : posição = %d e saida %c\n", i, str);
 	return (str);
 }

 int main()
 {
 	char str[10] = "banana";
 	printf("O resultado é: %s\n", str);
 	char *result = ft_strmapi(str, my_func);
 	printf("O resultado é: %s\n", result);
 	return 0;
 }
