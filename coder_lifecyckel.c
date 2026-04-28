/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecyckel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:17:26 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/28 18:35:45 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "codixion.h"

void	act_pars(t_coder	*coder, t_status	stat){
	add_manage_periority(coder, stat.scheduler_type);

	while (coder->right_dongle->priority_queue->front->value != coder)
		pthread_cond_wait(&cond, &coder->right_dongle->mutex);
	
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