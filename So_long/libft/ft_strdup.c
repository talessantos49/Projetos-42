/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 05:12:41 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/20 16:14:13 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*src)
{
	char	*target;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	target = malloc ((len + 1) * sizeof (char));
	while (src[i])
	{
		target[i] = src[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
