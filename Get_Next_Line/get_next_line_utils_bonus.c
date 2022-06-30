/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:17:27 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/10 22:28:57 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char	*string1, const char	*string2)
{
	char	*join;
	int		t;
	int		k;

	k = -1;
	t = -1;
	if (!string1)
	{
		string1 = (char *)malloc(1 * sizeof(char));
		string1[0] = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	join = malloc((ft_strlen(string2) + ft_strlen(string1) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (string1[++t])
		join[t] = string1[t];
	while (string2[++k])
		join[t + k] = string2[k];
	join[t + k] = '\0';
	free (string1);
	return (join);
}

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
