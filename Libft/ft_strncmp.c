/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:25:47 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/09 15:32:38 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*string, const char	*stringB, size_t i)
{
	unsigned int	j;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)string;
	s2 = (unsigned char *)stringB;
	j = 0;
	if (i == 0)
		return (0);
	while (s1[j] && j < i)
	{
		if (s1[j] != s2[j])
			return (s1[j] - s2[j]);
		j++;
	}
	if (s1[j] == '\0')
		return (s1[j] - s2[j]);
	return (0);
}
