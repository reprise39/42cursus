/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:59:44 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/13 19:04:29 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define map_maxsize 1000000

typedef struct s_map
{
	char *contents[map_maxsize];
	int *map_x[map_maxsize];
	int *map_y[map_maxsize];
}	t_map;

# endif