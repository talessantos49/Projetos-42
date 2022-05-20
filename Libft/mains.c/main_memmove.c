/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:19:55 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/12 04:22:00 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

void	*ft_memmove(void	*dest, void	*src, size_t	num);
  
int main(){
  char fonte[5] = "BCC";
  char destino[50] = "Programa de Ensino e Tutoria";
  printf("Bloco de memória fonte: %s\n", fonte);
  printf("Bloco de memória de destino: %s\n\n", destino);
  
  // Utilizamos sizeof() para contar exatamente o número de bytes do
  // bloco de memória fonte.
  ft_memmove(destino, fonte, sizeof(fonte));
  printf("Bloco de memória de destino após ser movido:\n");
  printf("%s\n", destino);
  
  return 0;
}	