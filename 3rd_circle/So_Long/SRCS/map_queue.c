/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:08 by mkuida            #+#    #+#             */
/*   Updated: 2025/03/21 16:44:01 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "queue.h"
# include "so_long.h"

void queue_init(t_map_queue *queue)
{	
	int i;
	
	i = 0;
	queue->top = 0;
	queue->tail = 0;
	while(i < queue_maxsize)
	{
		(queue->point[i]).x = 0;
		(queue->point[i]).y = 0;
		i++;
	}
}

int isEmpty(t_map_queue *queue)
{
	if(queue->top == queue->tail)
		return (1);
	else
		return (0);
}

int isFull(t_map_queue *queue)
{
	int top_value;
	int tail_value;

	top_value = queue->top;
	tail_value = queue->tail;
	if(top_value == (tail_value + 1) % queue_maxsize)
		return (1);
	else
		return (0);
}

int enqueue(t_map_queue *que,int x,int y,char c)
{
	if(isFull(que))
		return (-1);
	que->point[que->tail].x = x;
	que->point[que->tail].y = y;
	que->tail++;
	if(que->tail == queue_maxsize)
		que->tail = 0;
	return (1);
}

t_point dequeue(t_map_queue *que)
{
	t_point res;
	
	res.x = 0;
	res.y = 0;
	if(isEmpty(que))
		return (res);
	res.x = que->point[que->top].x;
	res.y = que->point[que->top].y;
	que->top++;
	if(que->top == queue_maxsize)
		que->top = 0;
	return (res);	
}
