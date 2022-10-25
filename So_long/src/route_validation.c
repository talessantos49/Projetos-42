/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:06:02 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/25 02:32:28 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	route_validation(t_game *game, int x, int y)
{
	if (game->map.route[x][y] == '1' || game->map.route[x][y] == 'X')
		return ;
	if (game->map.route[x][y] == '0' || game->map.route[x][y] == 'C' ||
		game->map.route[x][y] == 'E' || game->map.route[x][y] == 'P')
	{
		if (game->map.route[x][y] == 'C')
			game->map.collection_points++;
		if (game->map.route[x][y] == 'E')
			game->map.count_exits++;
		game->map.route[x][y] = 'X';
		route_validation(game, x + 1, y);
		route_validation(game, x - 1, y);
		route_validation(game, x, y + 1);
		route_validation(game, x, y - 1);
		return ;
	}
}

void	map_is_path_valid(t_game *game)
{
	route_validation(game, game->map.init_y, game->map.init_x);
	if ((game->map.collection_points - game->saved_caps) == 0
		&& (game->map.count_exits == 1))
		return ;
	exit_map("ERROR-INVALID MAP PATH\n", game);
	return ;
}

void	player_inicial_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == 'P')
			{
				game->map.init_y = i;
				game->map.init_x = j;
			}
		}
	}
}
