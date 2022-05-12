/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:12:52 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/12 03:56:55 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_memcpy.c"

int main(){
  char fonte[5] = "BCC";
  char destino[50] = "Programa de Ensino e Tutoria";
  printf("Bloco de memória fonte: %s\n", fonte);
  printf("Bloco de memória de destino: %s\n\n", destino);
    
  // Utilizamos sizeof() para contar exatamente o número de bytes do
  // bloco de memória fonte.
  ft_memcpy(destino, fonte, sizeof(fonte));
  printf("Bloco de memória de destino após a cópia ser realizada:\n");
  printf("%s\n", destino);
    
  return 0;
}	
