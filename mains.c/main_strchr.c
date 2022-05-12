/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:09:13 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 14:22:26 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strrchr(const char *string, int c);

int	main()
{
	int	caractere = '\0';
	char	fonte[] = "Palavras jogadas para serem testadas SZ!";

	printf("Resposta esperada de encontro da letra : '%c' na frase : %s\n",caractere, fonte);
	if(ft_strrchr(fonte, caractere) != NULL)
	{
		printf("\nResultado Obtido: ");
		printf("\nCaractere %c encontrado!", caractere);
		printf("\nString a partir dele: %s\n ", ft_strrchr(fonte, caractere));
	}
		else
			printf("\n Caractere %c não encontrado!\n", caractere);
	if(strrchr(fonte, caractere) != NULL){
		printf("\nCaractere %c encontrado! \n", caractere);
		printf("String a partir dele: %s\n", strrchr(fonte, caractere));
	}
	else 
		printf("\n Caractere %c não encontrado! \n", caractere);
	return (0);
}