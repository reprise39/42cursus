/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:59:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/11 16:38:27 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define map_maxsize 100
# define map_maxsize_pow 10000

typedef struct s_map
{
	char contents[map_maxsize_pow];
	int map_x;
	int map_y;
}	t_map;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

# endif