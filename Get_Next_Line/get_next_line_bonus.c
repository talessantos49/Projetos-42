/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:04:47 by tasantos          #+#    #+#             */
/*   Updated: 2022/06/10 22:28:48 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char	*str)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_other(char	*str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	remainder = (char *)malloc((sizeof(char) * (ft_strlen(str) - i + 1)));
	if (!remainder)
		return (NULL);
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

char	*new_alocation(void)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*nextline[257];
	char		*line;
	char		*buffer;
	int			byte_read;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (fd > 256))
		return (NULL);
	byte_read = 1;
	buffer = new_alocation();
	while (byte_read > 0 && (!ft_strchr(nextline[fd], '\n')))
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		nextline[fd] = ft_strjoin(nextline[fd], buffer);
	}
	free(buffer);
	line = get_line(nextline[fd]);
	nextline[fd] = get_other(nextline[fd]);
	return (line);
}
