/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:14:06 by mkuida            #+#    #+#             */
/*   Updated: 2025/03/21 17:40:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# define queue_maxsize 1000000

# ifndef MAP_H
#  include "map.h"
#  define MAP_H
# endif

typedef struct s_map_queue
{
    int	top;
    int tail;
	t_point point[queue_maxsize];
}	t_map_queue;

# endif