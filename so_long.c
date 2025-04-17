/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/17 20:21:18 by tiagovr4         ###   ########.fr       */
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
		free_map(map);					// '.' is be used because the structure is being accessed directly. The '->' is only use if you have pointer to the structure
		return (1);
	}
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close, &game);		// This function execute an especific event, in this case, 17 is to close the window when 'X' is pressed
	mlx_loop(game.mlx);									// This function is the main loop of the game, it keeps the window open and processes events
	return (0);
}
