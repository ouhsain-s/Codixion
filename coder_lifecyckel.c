/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecyckel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:17:26 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/29 12:34:43 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "codixion.h"

void	print_action(int	id, char*	message, t_status	*stat)
{
	int	time_passed;

	pthread_mutex_lock(&stat->print_mutex);
		
		time_passed = get_current_time();
		time_passed -= stat->start_time; 
		printf("%ld %d %s", time_passed, id, message);
		pthread_mutex_unlock(&stat->print_mutex);
}
void	act_pars(t_coder	*coder, t_status	*stat){

	add_manage_periority(coder, stat->scheduler_type);
	
	pthread_mutex_lock(&coder->right_dongle->mutex);

	while (coder->right_dongle->priority_queue->front->value != coder)
		pthread_cond_wait(&coder->left_dongle->cond, &coder->right_dongle->mutex);
	print_action(coder->coder_id, " has taken a dongle", stat);
	pthread_mutex_lock(&coder->left_dongle->mutex);
	print_action(coder->coder_id, " has taken a dongle", stat);

	print_action(coder->coder_id, "is compiling", stat);
	usleep(stat->session_conf->time_to_compile);
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_cond_signal(&coder->right_dongle->cond);
}

void	act_debug(t_coder	*coder, t_status	*stat){
	print_action(coder->coder_id, "is debugging", stat);
	usleep(stat->session_conf->time_to_debug);
}

void	act_refactor(t_coder	*coder, t_status	*stat){
	print_action(coder->coder_id, "is refactoring", stat);
	usleep(stat->session_conf->time_to_refactor);
}

void    *coder_routine(void	*arg){
	t_thrad_args	*t_args;
	t_status		*status;
	t_coder			*coder;

	t_args = (t_thrad_args *)arg;
	status = t_args->status;
	coder = &status->set_of_coders[t_args->current_id];
			
	while (coder->num_of_compiled < status->session_conf->number_of_compiles)
	{
		act_pars(coder, status);
		act_debug(coder, status);
		act_refactor(coder, status);
		coder->num_of_compiled ++;
	}
	free(t_args);
	arg = NULL;
	return NULL;
}