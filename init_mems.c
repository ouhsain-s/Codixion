#include "mems.h"

void init_status(t_status *stat, int	n_cods, char	*scheduler){
	t_coder		*arr_coders;
	t_dongel	*arr_dongel;
	struct timeval	t;

	arr_coders = malloc(sizeof(t_coder) * n_cods);
	arr_dongel = malloc(sizeof(t_dongel) * n_cods);
	stat->scheduler_type = scheduler;
	stat->set_of_coders = arr_coders;
	stat->set_of_dongles = arr_dongel;
	stat->start_time = gettimeofday(&t, NULL);
	stat->start_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	stat->num_of_coders = n_cods;
}

void init_dongel(t_dongel *dongel){
    dongel->last_release_time = -1;
    pthread_mutex_init(&dongel->mutex, NULL);
    dongel->periorety_queue = malloc(sizeof(t_queue));
    init_queue(dongel->periorety_queue);
}

void init_coder(t_coder *coder, int id,t_dongel   *r_d, t_dongel    *l_d){
    coder->coder_id = id;
    coder->last_compiletime = -1;
    coder->left_dongle = l_d;
    coder->right_dongle = r_d;
    pthread_attr_init(&coder->thread_id);
}