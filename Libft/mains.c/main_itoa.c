/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:50:55 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/06 21:48:12 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n);

size_t ft_itoa_len(int n);

int	main(void)
{
	int	i = -2147483647;
	
	printf("O resultado é %li\n", ft_itoa_len(i));

	printf("O resultado é %s\n", ft_itoa(i));
}