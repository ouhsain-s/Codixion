/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_paradigm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:08 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/29 12:41:01 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "codixion.h"

void link_coders_with_dongles(t_status *stat){
	int	i;
	int	num_compile;
	t_dongle	*r;
	t_dongle	*l;

	i = 0;

	while (i < stat->session_conf->number_of_coders)
	{
		init_dongle(&stat->set_of_dongles[i]);
		i++;
	}
	i = 0;
	while (i < stat->session_conf->number_of_coders)
	{
		r = &stat->set_of_dongles[i];
		if (i < stat->session_conf->number_of_coders - 1)
			l = &stat->set_of_dongles[i + 1];
		else
			l = &stat->set_of_dongles[0];
		num_compile = stat->session_conf->number_of_compiles;
		stat->set_of_coders[i].num_of_compiled = num_compile;
		init_coder(&stat->set_of_coders[i], i, r, l);
		i++;
	}
}

void start_simulation(t_configs	*confs){
	t_status	systat;
	t_thrad_args	*args;
	char		*scheduler;
	int			i;

	i = 0;
	scheduler = confs->scheduler_type;
	init_status(&systat, confs);
	link_coders_with_dongles(&systat);
	while (i < confs->number_of_coders)
	{
		args = malloc(sizeof(t_thrad_args));
		args->current_id = i;
		args->status = &systat;
		pthread_create(&systat.set_of_coders[i].thread_id, NULL, &coder_routine, args);
	}
	i++;
}