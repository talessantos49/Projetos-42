/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:47:27 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/01 22:14:45 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *dest, size_t num);
  
int main(){
  char fonte[50] = "Programa de Ensino e Tutoria";
  int i = 0;
  printf("Bloco de memória fonte:\n%s\n\n", fonte);
  
  // Utilizamos sizeof() para contar exatamente o número de bytes do
  // bloco de memória fonte.
  ft_bzero(fonte, 9);
  printf("Bloco de memória de fonte após ser alterado:\n");
  while (i < 50)
  {
	  printf("%c", fonte[i]);
	  i++;
  }  
  printf("\n");
  return 0;
}	