/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:43:46 by mkuida            #+#    #+#             */
/*   Updated: 2025/03/23 15:28:56 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "map.h"
#include "so_long.h"

t_point get_startpoint(t_map *map_ptr)
{
	t_point start;
	int i;

	i = 0;
	while(map_ptr->contents[i] != 'P')
	{
		i++;
	}
	start.y = i / (map_ptr->map_x);
	start.x = i % (map_ptr->map_x);
	ft_printf("get_startpoint\n");
	ft_printf("x=%d y=%d\n",start.x,start.y);
	ft_printf("\n");
	return (start);
}

void bfs(t_map_queue *avaiable_flag_ptr,t_map *map_ptr,t_point start)
{
	t_map *explored_map;
	
	explored_map = mk_map_ptr(map_ptr->map_x,map_ptr->map_y);
	if(map_ptr == NULL)
		return (-1);
}

t_map_queue *enque_avaiable_flag(t_map *map_ptr,t_point start)
{
	//tukuru!
	t_map_queue *avaiable_flag_ptr;

	avaiable_flag_ptr = malloc(sizeof(t_map_queue*));
	if(avaiable_flag_ptr == NULL)
		return (NULL);
	queue_init(avaiable_flag_ptr);
	bfs(avaiable_flag_ptr,map_ptr,start);
	
	
	return(avaiable_flag_ptr);
}

t_map_queue *enque_goal(t_map *map_ptr,t_point start)
{
	//tukuru!
}

int check_reachable(t_map_queue *flag_ptr,t_map_queue *goal_ptr)
{
	//tukuru!
}

int check_isplayable_by_bfs(t_map *map_ptr)
{
	t_point start;
	t_map_queue *flag_ptr;
	t_map_queue *goal_ptr;
	
	start = get_startpoint(map_ptr);
	flag_ptr = enque_avaiable_flag(map_ptr,start);
	if(flag_ptr == NULL)
		return(-1);
	while(!isEmpty(flag_ptr))
	{
		goal_ptr = enque_goal(map_ptr,start);
		if(goal_ptr == NULL)
			return(-1);
		while(!isEmpty(goal_ptr))
		{
			if(check_reachable(flag_ptr,goal_ptr))
			{
				//free
				return (1);
			}
			dequeue(goal_ptr);
		}
		dequeue(flag_ptr);
	}
	//free
	return (-1);
}


// void output_maps(t_map *map_ptr)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while(i < map_ptr->map_y)
// 	{
// 		j = 0;
// 		while(j < map_ptr->map_x)
// 		{
// 			write(STDOUT_FILENO,map_ptr->contents[(i*(map_ptr->map_x))+j],1);
// 		}
// 	}
// }


t_map* install_map(t_map* map_ptr,int x,int y)
{
	int map_fd;
	char *line;
	int i;
	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	map_ptr->map_x = x;
	map_ptr->map_y = y;
	line = get_next_line(map_fd);
	i = 0;
	ft_printf("\n");
	while(i < y)
	{
		ft_strlcpy(&(map_ptr->contents[0 + (i*x)]),line,x);
		ft_printf("%s\n",line);
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	// free(line);
	close(map_fd);
	return(map_ptr);
}

t_map* mk_map_ptr(int x,int y)
{
	t_map* map_ptr;
	char* line;
	int i;
	int map_fd;

	map_ptr = malloc(sizeof(t_map));
	if(map_ptr == NULL)
		return (NULL);
	map_ptr = install_map(map_ptr,x,y);
	if(map_ptr == NULL)
	{
		free(map_ptr);
		return (NULL);
	}
	return (map_ptr);
}

int map_check_isplayable()
{
	t_map *map_ptr;
	int is_playable;
	const int w = get_map_width();
	const int h = get_map_height();

	map_ptr = mk_map_ptr(w,h);
	if(map_ptr == NULL)
		return (-1);
	is_playable = check_isplayable_by_bfs(map_ptr);
	free(map_ptr);
	return(is_playable);
}
