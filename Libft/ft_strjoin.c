/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:24:12 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 05:08:44 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char	*string1, const char	*string2)
{
	char	*join;
	int		t;
	int		k;

	k = 0;
	t = 0;
	join = malloc(ft_strlen(string2) + ft_strlen(string1) + 1);
	if (!join)
		return (NULL);
	while (string1[t])
	{
		join[t] = string1[t];
		t++;
	}
	while (string2[k])
	{
		join[t] = string2[k];
		t++;
		k++;
	}
	join[t] = '\0';
	return (join);
}
