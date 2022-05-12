/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:12:29 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/20 18:31:07 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

void	*ft_memchr(void	*src, int	c, size_t num);

int main(){
  int caractere = 'm';
  char *ponteiro;
  char *ponteiro2;
  char fonte[] = "Programa de Ensino e Tutoria - BCC";

  // Como é retornando um ponteiro do tipo "void", uma conversão deve ser
  // feita para um ponteiro de "char"
  ponteiro = (char *)ft_memchr(fonte, caractere, 10);  
  ponteiro2 = (char *)memchr(fonte, caractere, 10);
	printf("O retorno é: %p\n", ft_memchr(fonte,caractere,10));
	printf("O retorno da original é: %p\n", memchr(fonte, caractere, 10));
  printf("Localizar a primeira letra '%c' nos 10 primeiros bytes do bloco de memória", caractere);
  if(ponteiro != NULL){
    printf("\nCaractere %c encontrado na posição %ld\n", caractere, ponteiro-fonte+1);
  } else {
    printf("\nCaractere %c não encontrado!\n", caractere);
  }
  
    printf("Localizar a primeira letra '%c' nos 10 primeiros bytes do bloco de memória", caractere);
  if(ponteiro2 != NULL){
    printf("\nCaractere %c encontrado na posição %ld\n", caractere, ponteiro2-fonte+1);
  } else {
    printf("\nCaractere %c não encontrado!\n", caractere);
  }


  return 0;
}	
              