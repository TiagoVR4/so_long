/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:20:34 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 20:31:47 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This function loads the images for the game
static int	load_images(t_game *game, int *img_width, int *img_height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			img_width, img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			img_width, img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
			img_width, img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm",
			img_width, img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			img_width, img_height);
	if (!game->img_player || !game->img_wall || !game->img_floor
		|| !game->img_collect || !game->img_exit)
		return (0);
	return (1);
}

// Count the number of lines and set the map width and height
static void	count_map_dimensions(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
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
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
		}
		i++;
	}
}

int	init_game(t_game *game, char **map)
{
	int	img_width;
	int	img_height;

	game->map = map;
	find_map_elements(game);
	game->original_map = copy_map(map, game->map_height);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "So Long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	if (!load_images(game, &img_width, &img_height))
		return (0);
	return (1);
}
