/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:08 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/13 18:58:13 by mkuida           ###   ########.fr       */
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
		queue->map_x[i] = 0;
		queue->map_y[i] = 0;
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
	que->map_x[que->tail] = x;
	que->map_y[que->tail] = y;
	que->tail++;
	if(que->tail == queue_maxsize)
		que->tail = 0;
	return (1);
}

int dequeue(t_map_queue *que)
{
	int res;
	
	if(isEmpty(que))
		return (-1);
	res = que->map_x[que->top];
	que->top++;
	if(que->top == queue_maxsize)
		que->top = 0;
	return (res);	
}
