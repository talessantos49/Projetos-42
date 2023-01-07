/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:41:49 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 01:16:44 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*large, const char	*small, size_t n)
{
	unsigned int	i;
	int				k;
	int				len;
	char			*big;

	i = 0;
	len = ft_strlen(small);
	big = (char *)large;
	if (len == 0 || large == small)
		return (big);
	while (big[i] && (i < n))
	{
		k = 0;
		if (big[i] == small[k])
		{
			while ((i + k < n) && big[i + k] == small[k])
			{
				k++;
				if (!small[k])
					return (&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
