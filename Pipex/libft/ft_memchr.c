/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:29:22 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:54:51 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{		
		if ((char)c == (*(char *)src))
			return ((void *)(src));
		else
		{
			src++;
			i++;
		}
	}
	return (NULL);
}
