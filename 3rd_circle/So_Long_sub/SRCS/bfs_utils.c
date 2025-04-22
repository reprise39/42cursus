/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:29:04 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 19:46:36 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_playable(t_map *map, int goal_found)
{
	if (map->collectible_count_total == map->collectible_count_current
		&& goal_found == 1)
		return (1);
	else
		return (-1);
}

void	enqueue_bfs(t_queue *queue, t_map *map, int **visited, t_xy xy)
{
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};
	int			nx;
	int			ny;
	int			i;

	i = 0;
	while (i < 4)
	{
		nx = xy.x + dx[i];
		ny = xy.y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < map->map_width && ny < map->map_height)
		{
			if (!visited[ny][nx] && map->contents[ny][nx].floor_type != WALL)
			{
				if (enqueue(queue, nx, ny) == -1)
				{
					perror("enqueue_bfs : enqueue");
					exit(EXIT_FAILURE);
				}
				visited[ny][nx] = 1;
			}
		}
		i++;
	}
}

void	bfs_loop(t_map *map, t_queue *queue, int **visited, int *goal_found)
{
	t_queue_point	*node;
	t_xy			xy;

	while (!is_queue_empty(queue))
	{
		node = dequeue(queue);
		xy.x = node->x;
		xy.y = node->y;
		free(node);
		if (map->contents[xy.y][xy.x].floor_type == COLLECTIBLE)
			map->collectible_count_current++;
		if (map->contents[xy.y][xy.x].floor_type == EXIT)
			*goal_found = 1;
		enqueue_bfs(queue, map, visited, xy);
	}
}

int	**make_visited(int height, int width)
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
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	if (!visited)
		return ;
	while (i < height)
		free(visited[i++]);
	free(visited);
}
