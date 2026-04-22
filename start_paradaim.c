#include "mems.h"



void link_coders_with_dongels(t_status *stat){

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