/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:49:30 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 20:39:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

int	check_maps(void)
{
	if (map_check_exists() == -1)
		return (ERROR_MAP_EXISTS);
	if (map_check_charactor() == -1)
		return (ERROR_MAP_CHARACTOR);
	if (map_check_shape() == -1)
		return (ERROR_MAP_SHAPE);
	if (map_check_wall() == -1)
		return (ERROR_MAP_INWALL);
	if (map_check_number_of_elements() == -1)
		return (ERROR_MAP_ELEMENTS);
	// if(map_check_isplayable() == -1)
	// 	return (ERROR_MAP_CANT_PLAY);
	return (0);
}

int	map_check_exists(void)
{
	int	map_fd;

	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	close(map_fd);
	return (1);
}

int	map_check_charactor(void)
{
	int			map_fd;
	const char	*map_charactor = "01CEP\n";
	char		charactor_in_map;

	map_fd = open(MAP_PATH, O_RDONLY);
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

int	map_check_shape(void)
{
	const int	h = get_map_height();
	const int	w = get_map_width();

	if (h < 3 || w < 3)
		return (-1);
	return (1);
}
