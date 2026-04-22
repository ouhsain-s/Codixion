/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_paradigm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:37 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 15:09:37 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mems.h"

static void	init_all_dongles(t_status *stat)
{
	int	i;

	i = 0;
	while (i < stat->session_conf->number_of_coders)
	{
		init_dongle(&stat->set_of_dongles[i]);
		i++;
	}
}

static void	link_coder(t_status *stat, int i)
{
	t_dongle	*r;
	t_dongle	*l;
	int		num_compile;

	if (i < stat->session_conf->number_of_coders - 1)
	{
		r = &stat->set_of_dongles[i];
		l = &stat->set_of_dongles[i + 1];
	}
	else
	{
		r = &stat->set_of_dongles[i];
		l = &stat->set_of_dongles[0];
	}
	num_compile = stat->session_conf->number_of_compiles;
	stat->set_of_coders[i].num_of_compiles = num_compile;
	init_coder(&stat->set_of_coders[i], i, r, l);
}

static void	link_coders_with_dongles(t_status *stat)
{
	int	i;

	init_all_dongles(stat);
	i = 0;
	while (i < stat->session_conf->number_of_coders)
	{
		link_coder(stat, i);
		i++;
	}
}

void	start_simulation(t_configs *confs)
{
	t_status	systat;
	int		n_cods;
	char		*scheduler;

	n_cods = confs->number_of_coders;
	scheduler = confs->scheduler_type;
	init_status(&systat, confs);
	link_coders_with_dongles(&systat);
}