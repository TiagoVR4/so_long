/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:45:42 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/17 18:28:32 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This function renders a single tile on the map
static void	render_tiles(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 64, y & 64);		// Always render the floor first
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
	else if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x * 64, y * 64);
	else if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64, y * 64);
}

// This function closes the window and frees the resources
int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game->map_height);
	exit(0);
	return (0);
}

// This function renders the entire map
void	render_map(t_game *game)
{
	char	*moves_str;
	int		x;
	int		y;

	y = 0;
	moves_str = ft_itoa(game->moves);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tiles(game, x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, moves_str);
	free(moves_str);
}
