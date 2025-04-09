/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:51 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/04/09 19:05:53 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int ac, char **av)
{
	t_game game;

	if(ac != 2)
	{
		ft_printf("Ërror: Please insert ""file"".ber\n");
		return (1);
	}
	read_map(av[1], &game);
	validate_map(&map);
}