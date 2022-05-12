/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:58:26 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 05:25:51 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	if (start > i)
		return (ft_strdup(""));
	if (len > ft_strlen(src) - start)
		len = ft_strlen(src) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	j = -1;
	i = -1;
	while (src[++i])
		if (i == start)
			while (++j < len)
				sub[j] = src[j + i];
	sub[j] = '\0';
	return (sub);
}
