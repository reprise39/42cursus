/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:19:47 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 17:57:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char *map_path)
{
	int		map_fd;
	int		same_width_flag;
	int		linewidth;
	char	*line;

	same_width_flag = 1;
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	linewidth = ft_strlen(line);
	while (line != NULL)
	{
		if (linewidth != (int)ft_strlen(line))
			same_width_flag = -1;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	if (same_width_flag == 1)
		return (linewidth);
	else
		return (-1);
}

int	get_map_height(char *map_path)
{
	int		map_fd;
	int		lineheight;
	char	*line;

	lineheight = 0;
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		lineheight++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	return (lineheight);
}

int	check_map_number_of_char(char *map_path, char c)
{
	int		map_fd;
	char	*line;
	int		i;
	int		number_of_char;

	number_of_char = 0;
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		i = 0;
		while (i < (int)ft_strlen(line))
		{
			if (line[i] == c)
				number_of_char++;
			i++;
		}
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (number_of_char);
}
