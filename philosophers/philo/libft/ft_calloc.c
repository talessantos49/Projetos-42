/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:57:25 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/26 14:14:25 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitens, size_t size)
{
	void	*p;
	size_t	total;

	total = nitens * size;
	if (total > 2147483647)
		return (NULL);
	if (size > __SIZE_MAX__ / nitens)
		return (NULL);
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
