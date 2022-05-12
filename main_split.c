/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:38:18 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 14:38:46 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

 int main()
 {
 	char str[20] = "Essa e a frase.";
 	char **result = ft_split(str, 'a');
 	printf("The result is %s\n", *result);
 	printf("The result is %s\n", result[0]);
 	printf("The result is %s\n", result[1]);
 	printf("The result is %s\n", result[2]);
 	return 0;
 }
