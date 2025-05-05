/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:50:57 by tiagovr4          #+#    #+#             */
/*   Updated: 2025/05/05 20:26:58 by tiagovr4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(const char *filename)
{
	char	*line;
	int		fd;
	int		lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while ((line = get_next_line(fd)))	// Read each line from the file
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

void	free_map(char **map)
{
	int	i;
	
	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// This function initializes the map and opens the file descriptor
static char	**init_map(const char *filename, int *lines, int *fd)
{
	char	**map;

	*lines = count_lines(filename);
	if (*lines < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (*lines + 1));
	if (!map)
		return (NULL);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

// This function clears the stash after reading the file
void	gnl_clear_stash(int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

char	**read_map(const char *filename)
{
	char	**map;
	int		fd;
	int		lines;
	int		i;

	map = init_map(filename, &lines, &fd);
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	gnl_clear_stash(fd);
	close(fd);
	return (map);
}
