/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:11:31 by tasantos          #+#    #+#             */
/*   Updated: 2022/04/12 01:11:37 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *dest, int c, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		((char *)dest)[i] = c;
		i++;
	}
	return (dest);
}
