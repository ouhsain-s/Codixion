/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:17:00 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/28 18:13:33 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mems.h"

void init_status(t_status	*stat, t_configs	*configs){
	t_coder			*arr_coders;
	t_dongle		*arr_dongle;
	struct timeval	t;

	arr_coders = malloc(sizeof(t_coder) * configs->number_of_coders);
	arr_dongle = malloc(sizeof(t_dongle) * configs->number_of_coders);
	stat->scheduler_type = configs->scheduler_type;
	stat->set_of_coders = arr_coders;
	stat->set_of_dongles = arr_dongle;
	stat->start_time = gettimeofday(&t, NULL);
	stat->start_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	stat->session_conf = configs;
}

void init_dongle(t_dongle	*dongle){
	dongle->last_release_time = -1;
	pthread_mutex_init(&dongle->mutex, NULL);
	dongle->priority_queue = malloc(sizeof(t_queue));
	init_queue(dongle->priority_queue);
}

void init_coder(t_coder	*coder, int	id,t_dongle	*r_d, t_dongle	*l_d){
	coder->coder_id = id;
	coder->last_compile_time = -1;
	coder->left_dongle = l_d;
	coder->right_dongle = r_d;
	coder->num_of_compiles = 0;
	pthread_attr_init(&coder->thread_id);
}
