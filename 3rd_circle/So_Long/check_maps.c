/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:49:30 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/26 20:54:26 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
# include <errno.h>

static int map_exists()
{
	int map_fd;
	
	map_fd = open(MAP_PATH, O_RDONLY);
	if(map_fd < 0)
		return (-1);
	close(map_fd);
	return (1);
}

static int map_check_charactor()
{
	int map_fd;
	const char *map_charactor = "01CEP\n";
	char charactor_in_map;
	map_fd = open(MAP_PATH, O_RDONLY);

	charactor_in_map = '0';
	while(charactor_in_map != EOF)
	{
		read(map_fd,charactor_in_map,1);
		if(ft_init(charactor_in_map,map_charactor)!= 1)
			return (-1);
	}
	return (1);
}

int check_maps()
{
	if(map_exists() == -1)
		return (ERROR_MAP_EXISTS);
	if(map_check_charactor() == -1)
		return (ERROR_MAP_CHARACTOR);
	if(map_check_chape() == -1)
		return (ERROR_MAP_SHAPE);
	if(map_check_wall() == -1)
		return (ERROR_MAP_INWALL);
	if(map_check_number_of_elements() == -1)
		return (ERROR_MAP_ELEMENTS);
	if(map_check_isplayable() == -1)
		return (ERROR_MAP_CANT_PLAY);	
	return (0);
}
