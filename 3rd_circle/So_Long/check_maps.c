/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:49:30 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/28 23:31:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
# include <errno.h>


int check_maps()
{
	if(map_check_exists() == -1)
		return (ERROR_MAP_EXISTS);
	if(map_check_charactor() == -1)
		return (ERROR_MAP_CHARACTOR);
	if(map_check_shape() == -1)
		return (ERROR_MAP_SHAPE);
	if(map_check_wall() == -1)
		return (ERROR_MAP_INWALL);
	if(map_check_number_of_elements() == -1)
		return (ERROR_MAP_ELEMENTS);
	// if(map_check_isplayable() == -1)
	// 	return (ERROR_MAP_CANT_PLAY);	
	return (0);
}


int map_check_exists()
{
	int map_fd;
	map_fd = open(MAP_PATH, O_RDONLY);
	if(map_fd < 0)
		return (-1);
	close(map_fd);
	return (1);
}

int map_check_charactor()
{
	int map_fd;
	const char *map_charactor = "01CEP\n";
	char charactor_in_map;

	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
	{
		return (-1);
	}
	while(read(map_fd,&charactor_in_map,1) > 0)
	{
		if(ft_strchr(map_charactor,charactor_in_map) == NULL)
		{
			close(map_fd);
			return (-1);
		}
	}
	close(map_fd);
	return (1);
}

int map_check_shape()
{
	int map_fd;
	int linewidth;
	int lineheight;
	int return_val;
	char *line;

	return_val = 1;
	lineheight = 0;
	map_fd = open(MAP_PATH, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	line = get_next_line(map_fd);
	while(line != NULL)
	{		
		lineheight++;
		if(lineheight == 1)
			linewidth = ft_strlen(line);
		else if(linewidth != ft_strlen(line))
			return_val = -1;
		free(line);
		line = get_next_line(map_fd);
	}
	if(linewidth == lineheight)
		return_val = -1;
	close(map_fd);
	return (return_val);
}

