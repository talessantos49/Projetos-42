/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:58:26 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/13 08:07:03 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	s_len;
	unsigned int	sub_len;

	s_len = ft_strlen(s);
	i = 0;
	sub = NULL;
	if (start > s_len)
		return (ft_strdup(""));
	sub_len = ft_strlen(&s[start]);
	if (len > sub_len)
		len = sub_len;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
