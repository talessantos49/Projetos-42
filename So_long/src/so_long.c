/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:37:22 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/22 23:32:28 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_player_coordinates(t_game *game)
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
				game->y = i;
				game->x = j;
			}
		}
	}
}

void	map_dimensions(t_map *map, char *path_map, t_game *game)
{
	int		file;
	char	*buffer;

	buffer = ft_strdup("");
	file = map_file(path_map);
	if (file <= 0)
	{
		free(buffer);
		exit(1);
	}
	init_matrix(file, buffer, game);
	map->n_row = 0;
	while (map->matrix[map->n_row] != NULL)
	{	
		map->n_col = 0;
		while (map->matrix[map->n_row][map->n_col] != 0)
			map->n_col++;
		map->n_row++;
	}
	if (map->n_row < 3 || map->n_col < 3)
		exit_map("Error- INVALID MAP\n Map dimensions Invalid!\n", game);
	verify_first_last(game);
}

int	key_input(int key, t_game *game)
{
	update_player_coordinates(game);
	if (key == 'a')
		move_east(game);
	else if (key == 'd')
		move_west(game);
	else if (key == 'w')
		move_north(game);
	else if (key == 's')
		move_south(game);
	else if (key == 'q' || key == XK_Escape)
		clean_before_exit(game);
	ft_printf("MOVES :[%i]\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}

int	loop_hook(t_game *game)
{
	render_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arguments(argc, argv);
	initializing_values(&game);
	map_dimensions(&game.map, argv[1], &game);
	count_itens(&game);
	player_inicial_position(&game);
	map_is_path_valid(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.map.n_col) * 32,
			game.map.n_row * 32, "Capivarias");
	render_img(&game);
	mlx_expose_hook(game.win, render_map, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_key_hook(game.win, key_input, &game);
	mlx_loop(game.mlx);
	clean_before_exit(&game);
	return (0);
}
