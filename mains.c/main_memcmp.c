/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:59:30 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/20 19:05:53 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(void *src, void *dest, size_t num);
  
int main(){
  char fonteA[12] = "Computacao";
  char fonteB[12] = "Computador";
  printf("Bloco de memória A: %s\n", fonteA);
  printf("Bloco de memória B: %s\n", fonteB);
  printf("Valor da primeira comparação: %d\n\n", memcmp(fonteA, fonteB, sizeof(fonteA)));
  printf("Bloco de memória A: %s\n", fonteA);
  printf("Bloco de memória B: %s\n", fonteB);
  printf("Valor da primeira comparação(FT): %d\n\n", ft_memcmp(fonteA, fonteB, sizeof(fonteA)));

  char fonteC[12] = "BCC";
  char fonteD[12] = "BCC";
  printf("String C: %s\n", fonteC);
  printf("String D: %s\n", fonteD);
  printf("Valor da segunda comparação: %d\n\n", memcmp(fonteC, fonteD, sizeof(fonteC)));
  printf("String C: %s\n", fonteC);
  printf("String D: %s\n", fonteD);
  printf("Valor da segunda comparação(FT): %d\n\n", ft_memcmp(fonteC, fonteD, sizeof(fonteC)));  

  return 0;
}	