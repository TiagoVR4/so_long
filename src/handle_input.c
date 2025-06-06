/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:37:33 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/05/22 20:42:04 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This function checks if the game is complete
static int	is_game_complete(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->collected == game->collectibles)
	{
		ft_printf("Congratulations! You completed the game in %d moves and with %d resets!\n", game->moves + 1, game->reset_count);
		handle_close(game);
	}
	return (0);
}

// This function moves the player to the new position
static int	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')		// Check if the next tile is a wall
		return (0);
	is_game_complete(game, new_x, new_y);	// Check if the game is complete
	if (game->map[new_y][new_x] == 'C')
		game->collected++;
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';					// Set the exit position
	else
		game->map[game->player_y][game->player_x] = '1';					// Set the previous position to a wall
	game->map[new_y][new_x] = 'P';						// Set the new position
	game->player_x = new_x;								// Update the player's x position
	game->player_y = new_y;								// Update the player's y position
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
	return (1);
}

static void	reset_game(t_game *game)
{
	int	i;
	int	j;

	game->reset_count++;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			game->map[i][j] = game->original_map[i][j];
			if (game->original_map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
	game->moves = 0;
	game->collected = 0;
	render_map(game);
	ft_printf("Game reset!\n");
}

// This function handles the input from the user
int	handle_input(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)								// 'w' or up arrow
		return (move_player(game, game->player_x, game->player_y - 1));
	else if (keycode == 97 || keycode == 65361) 						// 'a' or left arrow
		return (move_player(game, game->player_x - 1, game->player_y));
	else if (keycode == 115 || keycode == 65364)						// 's' or down arrow
		return (move_player(game, game->player_x, game->player_y + 1));
	else if (keycode == 100 || keycode == 65363)						// 'd' or right arrow
		return (move_player(game, game->player_x + 1, game->player_y));
	else if (keycode == 114)											// 'r' to restart the game
	{
		reset_game(game);
		return(1);
	}
	else if (keycode == 65307)											// 'esc'
		handle_close(game);
	return (0);
}
