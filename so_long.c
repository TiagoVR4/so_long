/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/29 16:51:21 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;

	if(ac != 2)
	{
		ft_putstr_fd("Error: Please insert \"file\".ber\n", 2);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	map = read_map(av[1]);
	if (!map)
	{
		ft_putstr_fd("Error: Failed to read map\n", 2);
		return (1);
	}
	if (!validate_map(map))
	{
		free_map(map);
		return (1);
	}
	if (!init_game(&game, map))
	{
		ft_putstr_fd("Error: Failed to initialize game\n", 2);
		free_map(map);
		return (1);
	}
	if (!validate_path(map, &game))
	{
		free_map(map);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close, &game);		// This function handle the close event, it will call the handle_close function when the window is closed
	mlx_key_hook(game.win, handle_input, &game);		// This function handle the input from the user, it will call the handle_input function when a key is pressed
	mlx_loop(game.mlx);									// This function is the main loop of the game, it keeps the window open and processes events
	return (0);
}
