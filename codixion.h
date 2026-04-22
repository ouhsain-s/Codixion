#ifndef CODIXION_H
#define CODIXION_H

#include <stdio.h>
#include <stdlib.h>
#include "mems.h"

int	ft_atoi(char	*str);
int get_num_of_coders(char	*num_coders);
int get_time(char	*str_time);
char *get_scheduler(char	*type);
void start_simulation(t_configs *confs);
#endif