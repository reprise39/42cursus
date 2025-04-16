/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:46 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 18:35:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_isplayable_by_bfs(t_map *map, t_queue *queue)
{
	int	**visited;
	int	goal_found;

	goal_found = 0;
	visited = make_visited(map->map_height, map->map_width);
	if (visited == NULL)
		return (-1);
	enqueue(queue, map->player_x, map->player_y);
	visited[map->player_y][map->player_x] = 1;
	bfs_loop(map, queue, visited, &goal_found);
	free_visited(visited, map->map_height);
	return (check_playable(map, goal_found));
}

int	map_check_isplayable(void)
{
	t_map	*map_ptr;
	t_queue	*queue_ptr;
	int		is_playable;

	map_ptr = make_map();
	if (map_ptr == NULL)
		return (-1);
	queue_ptr = init_queue();
	if (queue_ptr == NULL)
	{
		free_map(map_ptr);
		return (-1);
	}
	is_playable = check_isplayable_by_bfs(map_ptr, queue_ptr);
	free_map(map_ptr);
	free(queue_ptr);
	return (is_playable);
}
