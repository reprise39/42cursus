/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:46 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/13 19:52:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "map.h"
#include "so_long.h"

void install_map(t_map *map_ptr)
{
	int map_fd;
	const int w = get_map_width();
	const int h = get_map_height();
	char* line;
	int i;

	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
		return ;
	line = get_next_line(map_fd);
	i = 0;
	while(i < h)
	{
		install_line(map_ptr,line,w,h);
		i++;
	}
}


int map_check_isplayable()
{
	t_map_queue que;
	t_map *map_ptr;

	int i;

	map_ptr = malloc(sizeof(t_map));
	install_map(map_ptr);

	
	
}