/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:16:50 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 18:19:27 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

// This function try to find a path from the player position to the exit
static int	try_path(char **map, int x, int y, t_valid *valid)
{
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		valid->collectibles_found++;
	if (map[y][x] == 'E')
		valid->exit_found = 1;
	map[y][x] = '1';
	if (valid->collectibles_found == valid->total_collectibles
		&& valid->exit_found)
		return (1);
	if (try_path(map, x + 1, y, valid))
		return (1);
	if (try_path(map, x - 1, y, valid))
		return (1);
	if (try_path(map, x, y + 1, valid))
		return (1);
	if (try_path(map, x, y - 1, valid))
		return (1);
	return (0);
}

// This function tries to find a path from the player position to the exit
int	validate_path(char **map, t_game *game)
{
	char	**map_copy;
	t_valid	valid;
	int		result;

	map_copy = copy_map(map, game->map_height);
	if (!map_copy)
		return (0);
	valid.collectibles_found = 0;
	valid.exit_found = 0;
	valid.total_collectibles = game->collectibles;
	result = try_path(map_copy, game->player_x, game->player_y, &valid);
	free_map(map_copy);
	if (!result)
		ft_putstr_fd("Error: The player can't find the exit\n", 2);
	return (result);
}
