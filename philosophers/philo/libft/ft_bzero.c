/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:45:12 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:56:37 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		((char *)dest)[i] = '\0';
		i++;
	}
	return ;
}
