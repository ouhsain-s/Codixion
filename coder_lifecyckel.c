/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecyckel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:17:26 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/29 10:55:07 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "codixion.h"

void	act_pars(t_coder	*coder, t_status	stat){
	add_manage_periority(coder, stat.scheduler_type);
	
	pthread_mutex_lock(&coder->right_dongle->mutex);

	while (coder->right_dongle->priority_queue->front->value != coder)
		pthread_cond_wait(&coder->left_dongle->cond, &coder->right_dongle->mutex);

	pthread_mutex_lock(&coder->left_dongle->mutex);

	//worck will be here
	
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_cond_signal(&coder->right_dongle->cond);
}
void    *coder_routine(void	*arg){
	t_thrad_args	*t_args;
	t_status		*status;
	t_coder			*coder;

	t_args = (t_thrad_args *)arg;
	status = t_args->status;
	coder = &status->set_of_coders[t_args->current_id];
			
	while (coder->num_of_compiles < 2)
	{
		act_pars();
		act_debug();
		act_refactor();
		coder->num_of_compiles ++;
	}
	
	return NULL;
}