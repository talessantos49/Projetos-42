/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:10:53 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 16:36:33 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	reverse_copy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		dest++;
		src++;
		i--;
	}
	while (i < n)
	{
		dest--;
		src--;
		*dest = *src;
		i++;
	}
}

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	size_t	i;
	char	*auxdest;
	char	*auxsrc;

	i = 0;
	auxsrc = (char *)src;
	auxdest = (char *)dest;
	if (!auxsrc && !auxdest)
		return (0);
	if (auxsrc > auxdest)
	{
		while (i < n)
		{
			auxdest[i] = auxsrc[i];
			i++;
		}		
	}
	else
		reverse_copy(auxdest, auxsrc, n);
	return (auxdest);
}
