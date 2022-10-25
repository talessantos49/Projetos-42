/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:35 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/22 23:30:52 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_matrix(int filename, char *buffer, t_game *game)
{
	char	*line;

	while (1)
	{
		line = get_next_line(filename);
		if (!line)
			break ;
		buffer = ft_strjoin_gnl(buffer, line);
		free(line);
	}
	game->map.matrix = ft_split(buffer, '\n');
	game->map.route = ft_split(buffer, '\n');
	free(buffer);
}

void	insert_sprite(t_game *game, int x, int y, char	*image_ptr)
{
	mlx_put_image_to_window(game->mlx, game->win,
		image_ptr, (x * 32), (y * 32));
	return ;
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == '1')
				insert_sprite(game, j, i, game->wall.ptr);
			if (game->map.matrix[i][j] == '0')
				insert_sprite(game, j, i, game->floor.ptr);
			if (game->map.matrix[i][j] == 'C')
				insert_sprite(game, j, i, game->collect.ptr);
			if (game->map.matrix[i][j] == 'P')
				insert_sprite(game, j, i, game->character.ptr);
			if (game->map.matrix[i][j] == 'E')
				insert_sprite(game, j, i, game->exit.ptr);
		}
	}
	return (0);
}

int	map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n File \"%s\" doesn't exist\n", filename);
		close(fd);
		return (fd);
	}
	return (fd);
}

void	verify_first_last(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (!(ft_strchr ("10PCE", game->map.matrix[i][j])))
				exit_map("Error-INVALID MAP\nIncorrect Attributes!\n", game);
			if (game->map.matrix[0][j] != '1')
				exit_map("Error-INVALID MAP\nWall around Invalid!\n", game);
			if (game->map.matrix[game->map.n_row - 1][j] != '1')
				exit_map("Error-INVALID MAP\nWall around Invalid!\n", game);
		}
		if (game->map.matrix[i][j - 1] != '1')
			exit_map("Error-INVALID MAP\nMap Around Invalid!\n", game);
		if (game->map.matrix[i][0] != '1')
			exit_map("Error- INVALID MAP\nMap missing wall!\n", game);
		if (game->map.matrix[i][game->map.n_col] != game->map.matrix[0][j])
			exit_map("Error- INVALID MAP\nMap around Invalid!\n", game);
	}
}
