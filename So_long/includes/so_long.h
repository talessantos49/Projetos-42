/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:34 by tasantos          #+#    #+#             */
/*   Updated: 2022/10/23 05:15:39 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "libft.h"

# define FLOOR 	"./images/backgrouds/Grass.xpm"
# define WATER	"./images/backgrouds/Water.xpm"
# define COLLECT "./images/sprites/capy_red.xpm"
# define HERO "./images/sprites/capy.xpm"
# define WALL "./images/backgrouds/cut_tree.xpm"

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}	t_img;

typedef struct s_map
{
	char	**matrix;
	char	**route;
	int		init_x;
	int		init_y;
	int		pos_y;
	int		pos_x;
	int		end_y;
	int		end_x;
	int		collection_points;
	int		count_exits;
	int		n_col;
	int		n_row;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	character;
	t_img	floor;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	int		moves;
	int		x;
	int		y;
	int		itens;
	int		saved_caps;
	int		hero;
	int		end_game;
}	t_game;

int			map_file(char	*filename);
void		init_matrix(int filename, char *buffer, t_game *game);
void		exit_error(char *string, t_game *game);
void		verify_first_last(t_game *game);
void		map_dimensions(t_map *map, char *path_map, t_game *game);
void		*render_img(t_game *game);
void		insert_sprite(t_game *game, int x, int y, char *image_ptr);
int			render_map(t_game *game);
void		count_itens(t_game *game);
void		update_player_coordinates(t_game *game);
void		move_north(t_game *game);
void		move_south(t_game *game);
void		move_west(t_game *game);
void		move_east(t_game *game);
int			key_input(int key, t_game *game);
void		check_arguments(int argc, char **argv);
int			exit_game(t_game *game);
int			loop_hook(t_game *game);
void		free_matrix(t_game *game);
void		free_images(t_game *game);
void		free_window(t_game *game);
int			clean_before_exit(t_game *game);
void		initializing_values(t_game *game);
void		map_is_path_valid(t_game *game);
void		route_validation(t_game *game, int x, int y);
void		player_inicial_position(t_game *game);
void		exit_map(char *string, t_game *game);

#endif