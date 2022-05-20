/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:38:07 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/21 21:28:46 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char	*str);

int main()
{
   int val;
   int val2;
   char str[20];
   
   strcpy(str, "98993489");
   val = ft_atoi(str);
   val2 = atoi(str);
   printf("Entrada = %s, Resultado 1 = %d\n", str, val);
   printf("Entrada = %s, Resultado 2 = %d\n", str, val2);

   strcpy(str, "54614");
   val = ft_atoi(str);
   val2 = atoi(str);
   printf("Entrada = %s, Resultado 1 = %d\n", str, val);
   printf("Entrada = %s, Resultado 2 = %d\n", str, val2);
   
   return(0);
}