#ifndef MEMS_H
#define MEMS_H

#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct args_t{
   int number_of_coders;
   int time_to_burnout;
   int time_to_compile;
   int time_to_debug;
   int time_to_refactor;
   int number_of_compiles_required;
   int dongle_cooldown;
   char *scheduler;
} configs_t;

typedef struct dangels{
   pthread_mutex_t mutex;
   bool is_avaliable;
   bool timeto_willbe_avaliable;
   t_queue *periorety_queue;
}dangel_t;

typedef struct coders{
   int coder_id;
   dangel_t *left_dangel;
   dangel_t *rigth_dangel;
} coders_t;

#endif