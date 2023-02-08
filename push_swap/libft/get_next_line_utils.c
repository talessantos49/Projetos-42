/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:17:27 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/05 23:56:23 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char	*string1, const char	*string2)
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
