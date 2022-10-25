/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:14:46 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/24 06:06:33 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*render_img(t_game *game)
{
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->floor.width, &game->floor.height);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx, WATER,
			&game->exit.width, &game->exit.height);
	game->collect.ptr = mlx_xpm_file_to_image(game->mlx, COLLECT,
			&game->collect.width, &game->collect.height);
	game->character.ptr = mlx_xpm_file_to_image(game->mlx, HERO,
			&game->character.width, &game->character.height);
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->wall.width, &game->wall.height);
	return (0);
}

void	exit_error(char *string, t_game *game)
{
	ft_printf("%s\n", string);
	clean_before_exit(game);
}

void	count_itens(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == 'C')
				game->saved_caps++;
			if (game->map.matrix[i][j] == 'P')
				game->hero++;
			if (game->map.matrix[i][j] == 'E')
				game->end_game++;
		}
	}
	if (game->hero != 1)
		exit_map("ERROR - INVALID MAP\nWrong amount of character!\n", game);
	if (game->saved_caps <= 0)
		exit_map("ERROR - INVALID MAP\nNot Found any collect iten!\n", game);
	if (game->end_game <= 0)
		exit_map("ERROR - INVALID MAP\nNot found any exit point!\n", game);
}

void	check_arguments(int argc, char **argv)
{
	int	map_parameter_len;

	if (argc > 2)
	{
		ft_printf("ERROR\nToo many arguments\n");
		exit(1);
	}
	if (argc < 2)
	{
		ft_printf("ERROR\nToo few arguments\nThe Map file is missing.\n");
		exit(1);
	}
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
	{
		ft_printf("Map file extention is wrong (It should be .ber).\n");
		exit(1);
	}
}

int	exit_game(t_game *game)
{
	game->moves = 0;
	clean_before_exit(game);
	return (0);
}
