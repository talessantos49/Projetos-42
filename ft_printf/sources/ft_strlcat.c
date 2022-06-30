/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:40:40 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 22:08:29 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	size_t	i;
	size_t	tamanho_src;
	size_t	tamanho_dest;
	char	*aux_src;

	aux_src = (char *)src;
	i = 0;
	tamanho_src = ft_strlen(src);
	tamanho_dest = ft_strlen(dest);
	if (size <= tamanho_dest)
		return (size + tamanho_src);
	while (aux_src[i] && ((tamanho_dest + i) < (size -1)))
	{
		dest[tamanho_dest + i] = aux_src[i];
		i++;
	}
	dest[tamanho_dest + i] = '\0';
	return (tamanho_src + tamanho_dest);
}
