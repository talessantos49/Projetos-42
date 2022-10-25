/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:30:10 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/22 23:45:48 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game)
{
	void	*screen;

	screen = game->mlx;
	mlx_destroy_image(screen, game->floor.ptr);
	mlx_destroy_image(screen, game->wall.ptr);
	mlx_destroy_image(screen, game->collect.ptr);
	mlx_destroy_image(screen, game->character.ptr);
	mlx_destroy_image(screen, game->exit.ptr);
}

void	free_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.n_row)
	{
		free(game->map.matrix[i]);
		free(game->map.route[i]);
		i++;
	}
	free(game->map.matrix);
	free(game->map.route);
}

int	clean_before_exit(t_game *game)
{
	free_matrix(game);
	free_images(game);
	free_window(game);
	ft_printf("\n");
	exit(0);
	return (0);
}

void	exit_map(char *string, t_game *game)
{
	ft_printf("%s\n", string);
	free_matrix(game);
	exit(1);
}
