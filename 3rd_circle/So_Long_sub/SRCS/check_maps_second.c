/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:28:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 20:58:29 by mkuida           ###   ########.fr       */
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

int	map_check_wall_at(char *map_path, int map_height, int map_width)
{
	int		map_fd;
	int		my_height;
	int		rtn_val;
	char	*line;

	rtn_val = 1;
	my_height = 0;
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		my_height++;
		if (check_line(line, my_height, map_height, map_width) != 1)
			rtn_val = -1;
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (rtn_val);
}

int	map_check_wall(char *map_path)
{
	const int	map_height = get_map_height(map_path);
	const int	map_width = get_map_width(map_path);

	if (map_height < 0 || map_width < 0)
		return (-1);
	if (map_check_wall_at(map_path, map_height, map_width) == -1)
		return (-1);
	else
		return (1);
}

int	map_check_number_of_elements(char *map_path)
{
	int	number_of_char;

	number_of_char = check_map_number_of_char(map_path, 'C');
	if (number_of_char < 1)
		return (-1);
	number_of_char = check_map_number_of_char(map_path, 'E');
	if (number_of_char != 1)
		return (-1);
	number_of_char = check_map_number_of_char(map_path, 'P');
	if (number_of_char != 1)
		return (-1);
	return (1);
}

int	map_check_insize(char *map_path)
{
	const int	map_height = get_map_height(map_path);
	const int	map_width = get_map_width(map_path);

	if (map_height > MAP_MAXHEIGHT)
		return (-1);
	if (map_width > MAP_MAXWIDETH)
		return (-1);
	return (1);
}
