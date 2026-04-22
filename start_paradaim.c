#include "mems.h"



void link_coders_with_dongels(t_status *stat){
	int	i;
	t_dongel	*r;
	t_dongel	*l;

	i = 0;

	while (i < stat->num_of_coders)
	{
		init_dongel(stat->set_of_dongles[i]);
	}
	i = 0;
	while (i < stat->num_of_coders)
	{
		if (i < stat->num_of_coders - 1)
		{
			r = &stat->set_of_dongles[i];
			l = &stat->set_of_dongles[i + 1];
		}
		else{
			r = &stat->set_of_dongles[i];
			l = &stat->set_of_dongles[0];
		}
		init_coder(stat->set_of_coders[i], r, l);
	}
}

void start_semulation(t_configs	*confs){
	t_status	systat;
	int			n_cods;
	char		*scheduler;

	n_cods = confs->number_of_coders;
	scheduler = confs->scheduler_type;
	init_status(&systat, n_cods, scheduler);
	link_coders_with_dongels(&systat)
}