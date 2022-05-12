/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:21:47 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/29 19:03:37 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(const char	*string1, const char	*string2);

int	main(void)
{
	char	str1[] = " Eu já dei risada até a barriga doer,Já nadei até perder o fôlego, Já chorei até dormir E acordei com o rosto desfigurado.";
	char	str2[] = " Já fiz cosquinha na minha irmã só pra ela parar de chorar,Já me queimei brincando com vela.";


	printf("O resultado e: %s\n", ft_strjoin(str1, str2));
}
