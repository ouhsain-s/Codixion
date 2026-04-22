/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:02:07 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 16:34:42 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "queue.h"

void init_queue(t_queue *q){
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(t_queue *q){
	return (q->front == NULL);
}

void enqueue(t_queue *q, void *value){
	t_node *new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;

	new_node->value = value;
	new_node->next = NULL;
	
	if(q->rear == NULL){
		q->front = new_node;
		q->rear = new_node;
	}
	else{
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

void    *dequeue(t_queue *q)
{
	t_node  *todel;
	void    *value;
	if (q->front == NULL)
		return NULL;
	todel = q->front;
	value = todel->value;
	q->front = todel->next;
	
	if (q->front == NULL)
		q->rear = NULL;
	
	free(todel);
	return value;
}

void    free_queue(t_queue *q){
	
	t_node *current;
	
	while (q->front){
		current = q->front;
		q->front = q->front->next;
		free(current);    
	}
	q->rear = NULL;
}