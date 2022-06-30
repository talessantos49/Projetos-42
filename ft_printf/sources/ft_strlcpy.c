/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:51 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 16:30:18 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t size)
{
	unsigned int	i;
	int				tamanho;
	char			*aux_src;

	i = 0;
	aux_src = (char *)src;
	tamanho = ft_strlen(src);
	if (size == 0)
		return (tamanho);
	while (aux_src[i] && (i < size - 1))
	{
		dest[i] = aux_src[i];
		i++;
	}
	dest[i] = '\0';
	return (tamanho);
}
