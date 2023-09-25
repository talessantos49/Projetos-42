/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:19:54 by tasantos          #+#    #+#             */
/*   Updated: 2022/08/25 23:28:27 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	cut;

	i = 0;
	j = 0;
	cut = 0;
	while (s1[i])
	{
		j = 0;
		cut = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				cut++;
			j++;
		}
		if (cut == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_end_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	cut;

	i = ft_strlen(s1) - 1;
	j = 0;
	cut = 0;
	while (i > 0)
	{
		j = 0;
		cut = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				cut++;
			j++;
		}
		if (cut == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const	*set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	start = ft_start_strtrim(s1, set);
	end = ft_end_strtrim(s1, set);
	if (s1 == NULL)
		return (0);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	if (end < start)
		return (ft_strdup(""));
	str = ft_substr(s1, start, (end - start) + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
