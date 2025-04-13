#include "so_long.h"

static int  is_rectangular(char **map)
{
    int i;
    int len;

    if (!mpa || !map[0])
        return (0);
    len = ft_strlen(map[0]); // Get the length of the first line
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != len) // Compare the length of each line
            return (0);
        i++;
    }
    return (1);
}

static int  valid_borders(char **map)
{
    int len;
    int i;

    len = ft_strlen(map[0]);
    i = 0;
    while (i < len)
    {
        if (map[0][i] != '1' || map[i][len - 1] != '1') // Check top and right borders
            return (0);
        i++;
    }
    return (1);
}
static int  required_elements(char **map)
{
    int i;
    int j;
    int player;
    int exit;
    int collectibles;

    player = 0;
    exit = 0;
    collectibles = 0;
    i = 0;
    while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j == 0;
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (player == 1 && exit >= 1 && collectibles >= 1);
}


int validate_map (char **map)
{
    if (!is_rectangular(map))
    {
        ft_putstr_fd("Error: Map borders are invalid.\n", 2);
        return (0);
    }
    if (!valid_borders(map))
    {
        ft_putstr_fd("Error: Map's borders are invalid.\n", 2);
        return (0);
    }
    if (!required_elements(map))
    {
        ft_putstr_fd("Error: Map does not contain required elements.\n", 2);
        return (0);
    }
    return (1);
}
