/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:10 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/05/22 12:54:05 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_game 
{
	void	*mlx;				// pointer for minilibx
	void	*win;				// pointer for window
	char	**map;				// map in array
	char	**original_map;		// store the original map if the player wants restart
	int		map_width;			// map width
	int		map_height;			// map height
	int		player_x;			// player's x position
	int		player_y;			// player's y position
	int		exit_x;
	int		exit_y;
	int		collectibles;		// collectibles counter
	int		collected;			// collectibles collected
	int		moves;				// move counter
	void	*img_player;		// player sprite
	void	*img_wall;			// wall sprite
	void	*img_floor;			// floor sprite
	void	*img_collect;		// collectible sprite
	void	*img_exit;			// exit sprite
} 				t_game;

typedef struct s_valid
{
	int	collectibles_found;
	int	exit_found;
}	t_valid;

//functions
char	**read_map(const char *filename);
char	**copy_map(char **map, int height);

void	free_map(char **map);
void	render_map(t_game *game);

int	validate_map(char **map);
int	main (int ac, char **av);
int	init_game(t_game *game, char **map);
int	handle_close(t_game *game);
int	handle_input(int keycode, t_game *game);
int	validate_path(char **map, t_game *game);
int	valid_char(char **map);


#endif