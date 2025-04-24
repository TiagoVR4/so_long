/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:10 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/24 17:10:58 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"

typedef struct	s_game 
{
	void	*mlx;				// pointer for minilibx
	void	*win;				// pointer for window
	char	**map;				// map in array
	int		map_width;			// map width
	int		map_height;
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

//functions
char	**read_map(const char *filename);

void	free_map(char **map);
void	render_map(t_game *game);

int	validate_map(char **map);
int	main (int ac, char **av);
int	init_game(t_game *game, char **map);
int	handle_close(t_game *game);
int	handle_input(int keycode, t_game *game);

#endif