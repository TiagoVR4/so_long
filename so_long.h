/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:10 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/15 11:55:46 by tiagovr4         ###   ########.fr       */
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
	void	*mlx;		// pointer for minilibx
	void	*win;		// pointer for window
	void	**map;		// map in array
	int		player_x;	// player's x position
	int		player_y;	// player's y position
	int		coins;		// collectibles counter
	int		moves;		//move counter
} 				t_game;

//functions
char	**read_map(const char *filename);

void	free_map(char **map, int lines);

int	validate_map(char **map);
int	main (int ac, char **av);

#endif