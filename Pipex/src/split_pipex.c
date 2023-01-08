/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:36:39 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/08 05:40:52 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	len_words_pipex(char const *str, char delimiter)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != delimiter && str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				i++;
				j++;
			}
		}
		i++;
		j++;
	}
	return (j);
}

static size_t	count_words_pipex(char const *str, char delimiter)
{
	size_t	i;
	size_t	words;

	if (!*str)
		return (0);
	i = 1;
	words = 0;
	while (str[i])
	{
		if (str[i] != delimiter && str[i])
		{
			if (str[i++] == '\'')
				while (str[i] != '\'')
					i++;
			words++;
			while (str[i] != delimiter && str[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_split_pipex(char const *str, char delimiter)
{
	char	**string;
	t_split	split;

	split.quote = '\'';
	if (!str)
		return (0);
	split.n_words = count_words_pipex(str, delimiter);
	string = (char **)malloc((split.n_words + 1) * sizeof(char *));
	if (!string)
		return (0);
	split.index = 0;
	while (split.index < split.n_words)
	{
		while (*str && *str == delimiter)
			str++;
		split.n_chars = len_words_pipex(str, delimiter);
		if (*str == '\'')
			string[split.index] = ft_strtrim(str, &split.quote);
		else
			string[split.index] = ft_substr(str, 0, split.n_chars);
		str += split.n_chars + 1;
		split.index++;
	}
	string[split.index] = 0;
	return (string);
}

void	error_and_exit(int number_exit, t_pipex *pipex)
{
	write(2, "bash: : command not found\n", 26);
	free_split(pipex->path_command);
	free_split(pipex->first_command_arg);
	exit(number_exit);
}
