/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:42:56 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 20:25:07 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_exists(char *filepath)
{
	int	map_fd;

	map_fd = open(filepath, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	close(map_fd);
	return (1);
}

static int	textures_readable(void)
{
	if (file_exists(TEXTURES_FLOOR_PATH) == -1)
		return (-1);
	if (file_exists(TEXTURES_PLAYER_PATH) == -1)
		return (-1);
	if (file_exists(TEXTURES_ASSET_PATH) == -1)
		return (-1);
	if (file_exists(TEXTURES_GOAL_PATH) == -1)
		return (-1);
	if (file_exists(TEXTURES_WALL_PATH) == -1)
		return (-1);
	return (0);
}

int	check_textures(void)
{
	if (textures_readable() == -1)
		return (ERROR_TEXTURES_UNREADABLE);
	return (0);
}
