/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:48:45 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/03 06:37:32 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int main(void)
{
	char string[] = "----+++TESLA+++----";
	char set[] = "-+";

	printf("O valor de saida: %s \n", ft_strtrim(string, set));
	printf("O valor de string é: %s \n", string);
}
