#ifndef INIT_MEMS_H
#define INIT_MEMS_H

#include "mems.h"

void init_status(t_status *stat,  t_configs	*configs);
void init_dongel(t_dongel *dongel);
void init_coder(t_coder *coder, int id,t_dongel	*r_d, t_dongel	*l_d);

#endif