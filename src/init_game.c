/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:20:34 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/05/07 19:50:51 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This function loads the images for the game
static int	load_images(t_game *game, int *img_width, int *img_height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", img_width, img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", img_width, img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", img_width, img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm", img_width, img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", img_width, img_height);
	if (!game->img_player || !game->img_wall || !game->img_floor || !game->img_collect || !game->img_exit)
		return (0);
	return (1);
}

// Count the number of lines and set the map width and height
static void	count_map_dimensions(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])		// Count the number of lines in the map
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')	// remove the newline character 
		game->map_width--;
	game->collectibles = 0;
	game->collected = 0;
	game->moves = 0;
}

// This function finds the player and collectibles in the map
static void	find_map_elements(t_game *game)
{
	int	i;
	int	j;

	count_map_dimensions(game);
	i = 0;
	while (i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)					// Check each character in the map
		{
			if (game->map[i][j] == 'C')				// Collectible
				game->collectibles++;
			else if (game->map[i][j] == 'P')		// Player position
			{
				game->player_y = i;
				game->player_x = j;
			}
			else if (game->map[i][j] == 'E')		// exit position
			{
				game->exit_y = i;
				game->exit_x = j;
			}
		}
		i++;
	}
}

// This function initializes the game by loading the images and creating a new window
int	init_game(t_game *game, char **map)
{
	int	img_width;
	int	img_height;

	game->map = map;
	find_map_elements(game);
	game->original_map = copy_map(map, game->map_height);
	game->mlx = mlx_init();									// Initialize the mlx(graphics library)
	if(!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_width * 64, game->map_height * 64, "So Long");		// Create a new window
	if(!game->win)
	{
		mlx_destroy_display(game->mlx);						// Destroy the display
		free(game->mlx);
		return (0);
	}
	if (!load_images(game, &img_width, &img_height))
		return (0);
	return (1);
}
