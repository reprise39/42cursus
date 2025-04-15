/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:28:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 06:33:07 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line, int my_height, int map_height, int map_width)
{
	int	i;

	if (my_height == 1 || my_height == map_height)
	{
		i = 0;
		while (i < map_width)
		{
			if (line[i] != '1')
				return (-1);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[map_width - 1] != '1')
			return (-1);
	}
	return (1);
}

int	map_check_wall_at(int map_height, int map_width)
{
	int		map_fd;
	int		my_height;
	char	*line;

	my_height = 0;
	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		my_height++;
		if (check_line(line, my_height, map_height, map_width) != 1)
		{
			free(line);
			close(map_fd);
			return (-1);
		}
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (1);
}

int	map_check_wall(void)
{
	const int	map_height = get_map_height();
	const int	map_width = get_map_width();

	if (map_height < 0 || map_width < 0)
		return (-1);
	if (map_check_wall_at(map_height, map_width) == -1)
		return (-1);
	else
		return (1);
}

int	map_check_number_of_elements(void)
{
	int		map_fd;
	int		number_of_char;
	int		i;
	char	*line;

	number_of_char = check_map_number_of_char('C');
	if (number_of_char < 1)
		return (-1);
	number_of_char = check_map_number_of_char('E');
	if (number_of_char != 1)
		return (-1);
	number_of_char = check_map_number_of_char('P');
	if (number_of_char != 1)
		return (-1);
	return (1);
}
