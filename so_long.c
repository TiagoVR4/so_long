/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/05/22 12:01:33 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_error(char *msg, char **map, t_game *game, int free_mlx)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (map)
		free_map(map);
	if (free_mlx && game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (1);
}

static int	is_ber(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (len > 4 && !ft_strncmp(filename + len - 4, ".ber", 4));
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;

	if(ac != 2)
		return (handle_error("Error: Please insert \"file\".ber\n", NULL, NULL, 0));
	ft_memset(&game, 0, sizeof(t_game));
	if (!is_ber(av[1]))
		return (handle_error("Error: File must have .ber extension\n", NULL, NULL, 0));
	map = read_map(av[1]);
	if (!map)
		return (handle_error("Error: Failed to read map\n", NULL, NULL, 0));
	if (!validate_map(map))
		return (handle_error(NULL, map, NULL, 0));
	if (!init_game(&game, map))
		return (handle_error("Error: Failed to initialize game\n", map, NULL, 0));
	if (!validate_path(map, &game))
		return (handle_error(NULL, map, &game, 1));
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close, &game);		// This function handle the close event, it will call the handle_close function when the window is closed
	mlx_key_hook(game.win, handle_input, &game);		// This function handle the input from the user, it will call the handle_input function when a key is pressed
	mlx_loop(game.mlx);									// This function is the main loop of the game, it keeps the window open and processes events
	return (0);
}
