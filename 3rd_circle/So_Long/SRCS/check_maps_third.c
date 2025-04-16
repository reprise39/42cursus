/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:46 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 17:44:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_playable(t_map *map, int collect_count, int goal_found)
{
	if (map->collectible_count_total == collect_count && goal_found)
		return (1);
	else
		return (-1);
}

static int	**make_visited(int height, int width)
{
	int	**visited;
	int	i;

	i = 0;
	visited = ft_calloc(height, sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			while (i > 0)
			{
				free(visited[i - 1]);
				i--;
			}
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static void	free_visited(int **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static int	check_isplayable_by_bfs(t_map *map, t_queue *queue)
{
	int				**visited;
	int				collect_count;
	int				goal_found;
	t_queue_point	*node;
	int				x;
	int				y;
	t_floor_state	tile;
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
	int				nx;
	int				ny;

	collect_count = 0;
	goal_found = 0;
	visited = make_visited(map->map_height, map->map_width);
	if (visited == NULL)
		return (-1);
	enqueue(queue, map->player_x, map->player_y);
	visited[map->player_y][map->player_x] = 1;
	while (!is_queue_empty(queue))
	{
		node = dequeue(queue);
		x = node->x;
		y = node->y;
		free(node);
		tile = map->contents[y][x].floor_type;
		if (tile == COLLECTIBLE)
			collect_count++;
		if (tile == EXIT)
			goal_found = 1;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < (map->map_width)
				&& ny < (map->map_height))
			{
				if (!visited[ny][nx]
					&& map->contents[ny][nx].floor_type != WALL)
				{
					enqueue(queue, nx, ny);
					visited[ny][nx] = 1;
				}
			}
		}
	}
	free_visited(visited, map->map_height);
	return (check_playable(map, collect_count, goal_found));
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
