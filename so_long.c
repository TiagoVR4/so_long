/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/16 13:00:38 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int ac, char **av)
{
	t_game game;
	char	**map;
	int		i;

	if(ac != 2)
	{
		ft_putstr_fd("Error: Please insert ""file"".ber\n", 2);
		return (1);
	}
	map = read_map(av[1]);
	if (!map)
	{
		ft_putstr_fd("Error: Failed to read map\n", 2);
		return (1);
	}
	if (!validate_map(map))
		return (1);
	i = 0;
	if (!init_game(game, map))
	{

	}
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
	free_map(map, i);
	return (0);
}