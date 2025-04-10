/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:10 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/10 18:59:06 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"


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

#endif