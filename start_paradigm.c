#include "mems.h"

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
		if (i < stat->session_conf->number_of_coders - 1)
		{
			r = &stat->set_of_dongles[i];
			l = &stat->set_of_dongles[i + 1];
		}
		else{
			r = &stat->set_of_dongles[i];
			l = &stat->set_of_dongles[0];
		}
		num_compile = stat->session_conf->number_of_compiles;
		stat->set_of_coders[i].num_of_compiles = num_compile;
		init_coder(&stat->set_of_coders[i], i, r, l);
		i++;
	}
}

void start_simulation(t_configs	*confs){
	t_status	systat;
	int			n_cods;
	char		*scheduler;

	n_cods = confs->number_of_coders;
	scheduler = confs->scheduler_type;
	init_status(&systat, confs);
	link_coders_with_dongles(&systat);
}