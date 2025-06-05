/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 20:43:31 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_error(char *msg, char **map, t_game *game, int free_mlx)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (map)
		free_map(map);
	if (free_mlx && game && game->mlx)
	{
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->img_collect)
			mlx_destroy_image(game->mlx, game->img_collect);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		if (game->original_map)
			free_map(game->original_map);
	}
	return (1);
}

// This function check if it is the right file extension
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

	if (ac != 2)
		return (handle_error("Error: Please insert \"file\".ber\n",
				NULL, NULL, 0));
	ft_memset(&game, 0, sizeof(t_game));
	if (!is_ber(av[1]))
		return (handle_error("Error: File must have .ber extension\n",
				NULL, NULL, 0));
	map = read_map(av[1]);
	if (!map)
		return (handle_error("Error: Failed to read map\n", NULL, NULL, 0));
	if (!validate_map(map))
		return (handle_error(NULL, map, NULL, 0));
	if (!init_game(&game, map))
		return (handle_error("Error: Failed to initialize game\n",
				map, NULL, 0));
	if (!validate_path(map, &game))
		return (handle_error(NULL, map, &game, 1));
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
