/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:37 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 15:09:37 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct s_node
{
	void		*value;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
}	t_queue;

void	init_queue(t_queue *q);
int	is_empty(t_queue *q);
void	enqueue(t_queue *q, void *value);
void	*dequeue(t_queue *q);
void	free_queue(t_queue *q);

#endif