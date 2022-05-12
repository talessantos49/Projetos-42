/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:40:35 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/28 15:56:53 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strdup(const char	*src);
 
int main()
{
    char source[] = "Talvez Deu Certo ein!";
    char	*alvo = strdup(source);
	char	*target2 = ft_strdup(source);
	
	printf("Como saiu: %s\n", target2);
    printf("Como deveria sair: %s\n", alvo);
    return 0;
}
