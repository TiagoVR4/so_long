/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:57:02 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 18:27:48 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_rectangular(char **map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

// This function checks if the map has walls on all borders
static int	check_border_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

// This function checks if the map has valid borders and dimensions
static int	valid_borders(char **map)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (height < 3)
		return (0);
	width = ft_strlen(map[0]) - 1;
	if (width < 3)
		return (0);
	if (!check_border_walls(map, width, height))
		return (0);
	return (1);
}

static int	required_elements(char **map)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collectibles;

	player = 0;
	exit = 0;
	collectibles = 0;
	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectibles++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collectibles >= 1);
}

int	validate_map(char **map)
{
	if (!is_rectangular(map))
	{
		ft_putstr_fd("Error: Map's size is invalid.\n", 2);
		return (0);
	}
	if (!valid_borders(map))
	{
		ft_putstr_fd("Error: Map's borders are invalid.\n", 2);
		return (0);
	}
	if (!valid_char(map))
	{
		ft_putstr_fd("Error: Map contain invalid characters.\n", 2);
		return (0);
	}
	if (!required_elements(map))
	{
		ft_putstr_fd("Error: Map doesn't contain required elements.\n", 2);
		return (0);
	}
	return (1);
}
