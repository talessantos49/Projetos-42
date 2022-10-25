/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:37:22 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/24 05:58:47 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_north(t_game *game)
{
	if (game->map.matrix[game->y - 1][game->x] == 'C')
		game->itens++;
	if (game->map.matrix[game->y - 1][game->x] != '1' &&
		game->map.matrix[game->y - 1][game->x] != 'E')
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y - 1][game->x] = 'P';
		game->moves++;
	}
	if ((game->map.matrix[game->y -1][game->x] == 'E') &&
		(game->itens == game->saved_caps))
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y - 1][game->x] = 'P';
		game->moves++;
		exit_error("CONGRATULATIONS!! - YOU WIN\n", game);
	}
}

void	move_south(t_game *game)
{
	if (game->map.matrix[game->y + 1][game->x] == 'C')
		game->itens++;
	if (game->map.matrix[game->y + 1][game->x] != '1' &&
		game->map.matrix[game->y + 1][game->x] != 'E')
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y + 1][game->x] = 'P';
		game->moves++;
	}
	if ((game->map.matrix[game->y + 1][game->x] == 'E') &&
		(game->itens == game->saved_caps))
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y + 1][game->x] = 'P';
		game->moves++;
		exit_error("CONGRATULATIONS!! - YOU WIN\n", game);
	}
}

void	move_west(t_game *game)
{
	if (game->map.matrix[game->y][game->x + 1] == 'C')
		game->itens++;
	if (game->map.matrix[game->y][game->x + 1] != '1' &&
		game->map.matrix[game->y][game->x + 1] != 'E')
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y][game->x + 1] = 'P';
		game->moves++;
	}
	if ((game->map.matrix[game->y][game->x + 1] == 'E') &&
		(game->itens == game->saved_caps))
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y][game->x + 1] = 'P';
		game->moves++;
		exit_error("CONGRATULATIONS!! - YOU WIN\n", game);
	}
}

void	move_east(t_game *game)
{
	if (game->map.matrix[game->y][game->x - 1] == 'C')
		game->itens++;
	if (game->map.matrix[game->y][game->x - 1] != '1' &&
		game->map.matrix[game->y][game->x - 1] != 'E')
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y][game->x - 1] = 'P';
		game->moves++;
	}
	if ((game->map.matrix[game->y][game->x - 1] == 'E') &&
		(game->itens == game->saved_caps))
	{
		game->map.matrix[game->y][game->x] = '0';
		game->map.matrix[game->y][game->x - 1] = 'P';
		game->moves++;
		exit_error("CONGRATULATIONS!! - YOU WIN\n", game);
	}
}

void	initializing_values(t_game *game)
{
	game->moves = 0;
	game->y = 0;
	game->x = 0;
	game->itens = 0;
	game->end_game = 0;
	game->saved_caps = 0;
	game->hero = 0;
	game->end_game = 0;
	game->map.pos_x = 1;
	game->map.pos_y = 1;
	game->map.collection_points = 0;
	game->map.count_exits = 0;
	game->map.init_x = 0;
	game->map.init_y = 0;
	game->map.n_col = 0;
	game->map.n_row = 0;
}
