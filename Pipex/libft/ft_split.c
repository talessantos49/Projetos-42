/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:55:09 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/11 02:57:32 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_words(char const *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != delimiter && str[i])
		i++;
	return (i);
}

static size_t	count_words(char const *str, char delimiter)
{
	size_t	i;
	size_t	aux;

	if (!*str)
		return (0);
	i = 1;
	aux = 0;
	while (str[i])
	{
		if (str[i] != delimiter && str[i])
		{
			aux++;
			while (str[i] != delimiter && str[i])
				i++;
		}
		else
			i++;
	}
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	size_t	n_chars;
	size_t	j;
	char	**string;

	if (!s)
		return (0);
	n_words = count_words(s, c);
	string = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!string)
		return (0);
	j = 0;
	while (j < n_words)
	{
		while (*s && *s == c)
			s++;
		n_chars = len_words(s, c);
		string[j] = ft_substr(s, 0, n_chars);
		s += n_chars + 1;
		j++;
	}
	string[j] = 0;
	return (string);
}
