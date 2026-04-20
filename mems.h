#ifndef MEMS_H
#define MEMS_H

#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "queue.h"


typedef struct s_configs{
   int number_of_coders;
   int time_to_burnout;
   int time_to_compile;
   int time_to_debug;
   int time_to_refactor;
   int number_of_compiles_required;
   int dongle_cooldown;
   char *scheduler;
} t_configs;

typedef struct s_dongel{
   pthread_mutex_t *mutex;
   t_queue *periorety_queue;
}t_dongel;

typedef struct s_coder{
   int coder_id;
   int thread_id;
   t_dongel *left_dangel;
   t_dongel *rigth_dangel;
   datetime last_compiletime;
   int num_of_compiles;
   
} t_coder;

#endif