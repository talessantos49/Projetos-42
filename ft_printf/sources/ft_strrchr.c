/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:13:50 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/13 05:53:29 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}
