/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:06:07 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:55:50 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int		i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0' || string[i] == c)
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
