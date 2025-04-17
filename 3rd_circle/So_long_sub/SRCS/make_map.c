/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:59:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 21:48:50 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "so_long.h"

static t_map	*make_map_ptr(int map_width, int map_height);
static void		install_map_struct(t_map *map);
static void		set_map_contents(t_map *map, char c, int x, int y);
static int		make_map_contents(t_map *map, int map_width, int map_height);

t_map	*make_map(void)
{
	t_map		*map;
	const int	map_width = get_map_width();
	const int	map_height = get_map_height();

	map = make_map_ptr(map_width, map_height);
	if (!map)
	{
		perror("make_map_ptr");
		return (NULL);
	}
	install_map_struct(map);
	return (map);
}

static t_map	*make_map_ptr(int map_width, int map_height)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		perror("make_map_ptr(ft_calloc)");
		exit(EXIT_FAILURE);
	}
	map->map_width = map_width;
	map->map_height = map_height;
	map->contents = ft_calloc(sizeof(t_point *), map_height);
	if (!map->contents)
	{
		perror("make_map_ptr(ft_calloc)");
		exit(EXIT_FAILURE);
	}
	make_map_contents(map, map_width, map_height);
	return (map);
}

static int	make_map_contents(t_map *map, int map_width, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		map->contents[i] = ft_calloc(sizeof(t_point), map_width);
		if (!map->contents[i])
		{
			while (--i >= 0)
				free(map->contents[i]);
			free(map->contents);
			free(map);
			perror("make_map_ptr(ft_calloc)");
			exit(-1);
		}
		i++;
	}
	return (0);
}

static void	install_map_struct(t_map *map)
{
	const int	map_fd = open(MAP_PATH, O_RDONLY);
	char		*line;
	int			i;
	int			j;

	i = 0;
	if (map_fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		j = 0;
		while (j < (map->map_width) && line[j] != '\0')
		{
			set_map_contents(map, line[j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	free(line);
	close(map_fd);
}

void	set_map_contents(t_map *map, char c, int y, int x)
{
	if (x >= (map->map_width) || y >= (map->map_height))
	{
		ft_printf("Error: map overflow at x=%d y=%d\n", x, y);
		exit(EXIT_FAILURE);
	}
	if (c == '1')
		map->contents[y][x].floor_type = WALL;
	else if (c == '0')
		map->contents[y][x].floor_type = EMPTY;
	else if (c == 'C')
	{
		map->contents[y][x].floor_type = COLLECTIBLE;
		map->collectible_count_total++;
	}
	else if (c == 'P')
	{
		map->contents[y][x].floor_type = EMPTY;
		map->player_x = x;
		map->player_y = y;
	}
	else if (c == 'E')
		map->contents[y][x].floor_type = EXIT;
}
