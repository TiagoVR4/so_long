/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:45:52 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/06/03 18:29:34 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// validate if the map contains only valid characters
int	valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C'
			&& map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
