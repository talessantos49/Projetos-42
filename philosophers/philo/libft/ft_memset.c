/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:11:31 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:54:59 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
