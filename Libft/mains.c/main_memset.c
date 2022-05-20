/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:09:35 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/12 00:50:24 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dest, int c, size_t num);
  
int main(){
  char dest[50] = "Tesla Motors Autonoma";
  printf("Bloco de memória fonte: %s\n\n", dest);

  ft_memset(dest, 'M', 10);
  printf("Bloco de memória de dest após ser alterado:\n");
  printf("%s\n", dest);
  
  return 0;
}	
    