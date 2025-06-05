/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:10 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 20:41:06 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_exit;
	char	**map;
	char	**original_map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		collected;
	int		moves;
	int		reset_count;
}				t_game;

typedef struct s_valid
{
	int	collectibles_found;
	int	total_collectibles;
	int	exit_found;
}	t_valid;

//functions
char	**read_map(const char *filename);
char	**copy_map(char **map, int height);

void	free_map(char **map);
void	render_map(t_game *game);

int		validate_map(char **map);
int		main(int ac, char **av);
int		init_game(t_game *game, char **map);
int		handle_close(t_game *game);
int		handle_input(int keycode, t_game *game);
int		validate_path(char **map, t_game *game);
int		valid_char(char **map);

#endif