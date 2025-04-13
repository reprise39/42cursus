/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:59:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/14 07:02:48 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_point
{
	int x;
	int y;
	enum e_map_type
	{
		EMPTY,
		WALL,
		COLLECTIBLE,
		PLAYER,
		EXIT,
	} type;
}	t_point;

typedef struct s_map
{
	t_point **contents;
	int map_width;
	int map_height;
	int player_x;
	int player_y;
	int collectible_count_current;
	int collectible_count_total;
}	t_map;



# endif