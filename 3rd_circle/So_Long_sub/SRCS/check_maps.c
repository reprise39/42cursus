/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:49:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 21:12:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

static int	check_args(int argc, char **argv);

int	check_maps(int argc, char **argv)
{
	char	*map_path;

	if (check_args(argc, argv) == -1)
		return (ERROR_ARGS);
	map_path = argv[1];
	if (map_check_exists(map_path) == -1)
		return (ERROR_MAP_EXISTS);
	if (map_check_charactor(map_path) == -1)
		return (ERROR_MAP_CHARACTOR);
	if (map_check_shape(map_path) == -1)
		return (ERROR_MAP_SHAPE);
	if (map_check_insize(map_path) == -1)
		return (ERROR_MAP_SIZE);
	if (map_check_wall(map_path) == -1)
		return (ERROR_MAP_INWALL);
	if (map_check_number_of_elements(map_path) == -1)
		return (ERROR_MAP_ELEMENTS);
	if (map_check_isplayable(map_path) == -1)
		return (ERROR_MAP_CANT_PLAY);
	return (0);
}

int	map_check_exists(char *map_path)
{
	int	map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	if (close(map_fd) == -1)
		return (-1);
	return (1);
}

int	map_check_charactor(char *map_path)
{
	int			map_fd;
	const char	*map_charactor = "01CEP\n";
	char		charactor_in_map;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
	{
		return (-1);
	}
	while (read(map_fd, &charactor_in_map, 1) > 0)
	{
		if (ft_strchr(map_charactor, charactor_in_map) == NULL)
		{
			close(map_fd);
			return (-1);
		}
	}
	close(map_fd);
	return (1);
}

int	map_check_shape(char *map_path)
{
	const int	h = get_map_height(map_path);
	const int	w = get_map_width(map_path);

	if (h < 3 || w < 3)
		return (-1);
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int	map_path_len;

	map_path_len = (int)ft_strlen(argv[1]);
	if (argc != 2)
		return (-1);
	if (map_path_len <= 4)
		return (-1);
	if (ft_strncmp(argv[1] + map_path_len - 4, ".ber", 4) != 0)
		return (-1);
	return (0);
}
