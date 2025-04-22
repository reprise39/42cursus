/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:08 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 18:40:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "so_long.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->top = NULL;
	queue->tail = NULL;
	return (queue);
}

int	enqueue(t_queue *queue, int x, int y)
{
	t_queue_point	*new_node;

	new_node = malloc(sizeof(t_queue_point));
	if (!new_node)
		return (-1);
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (queue->top == NULL)
	{
		queue->top = new_node;
		queue->tail = new_node;
	}
	else
	{
		queue->tail->next = new_node;
		queue->tail = new_node;
	}
	return (0);
}

t_queue_point	*dequeue(t_queue *queue)
{
	t_queue_point	*temp;

	if (!queue->top)
		return (NULL);
	temp = queue->top;
	queue->top = queue->top->next;
	if (queue->top == NULL)
		queue->tail = NULL;
	return (temp);
}

int	is_queue_empty(t_queue *queue)
{
	if (queue->top == NULL)
		return (1);
	else
		return (0);
}
