/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:14:06 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/13 18:57:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# define queue_maxsize 1000000

typedef struct s_queue
{
    int	top;
    int tail;
	int *map_x[queue_maxsize];
	int *map_y[queue_maxsize];
}	t_map_queue;


# endif