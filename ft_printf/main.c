/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 05:01:46 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/30 04:29:52 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str_input, ...);

int	main(void)
{/*
	char	*ptr = "Esforçado";
	char	*ptr2 = "Aventureira e Legal";
	char	only = 'T';
	int		i = 28;
	int		hexdex = 65165165;
	int		valor_ft;
	int		valor_orig;
	valor_ft = ft_printf("%cales eh %s e %%%% também uma pessoa %s. Ele tem %i anos, o codigo dele é: %x e %X, o endereço dele é: %p\n",only , ptr, ptr2, i, hexdex, hexdex, ptr);
	valor_orig = printf("%cales eh %s e %%%% também uma pessoa %s. Ele tem %i anos, o codigo dele é: %x e %X, o endereço dele é: %p\n",only , ptr, ptr2, i, hexdex, hexdex, ptr);
	printf("\nValor ft = %i", valor_ft);
	printf("\nValor Original = %i", valor_orig);
/*/
	unsigned int	valor_test;
	int				valor_ft;
	int				valor_orig;
	int				itoa_back;

	valor_test = 0;
	itoa_back = -1;
	valor_ft = ft_printf("\n1-O valor teste é: %u", valor_test );	
	valor_orig = printf("\n2-O valor teste é: %u", valor_test );
	ft_printf("\n3-Valor ft = %X\n4-O valor de Itoa é: %x\n", valor_ft, itoa_back);
	printf("\n5-Valor orig = %X\n6-O valor de Itoa é: %x\n", valor_orig, itoa_back);

}
