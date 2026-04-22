#ifndef MEMS_H
#define MEMS_H

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include "queue.h"
#include "init_mems.h"


typedef struct s_configs{
   int number_of_coders;
   int time_to_burnout;
   int time_to_compile;
   int time_to_debug;
   int time_to_refactor;
   int number_of_compiles;
   int dongle_cooldown;
   char *scheduler_type;
} t_configs;

typedef struct s_dongel{
   pthread_mutex_t   mutex;
   long last_release_time;
   t_queue *periorety_queue;
}t_dongel;

typedef struct s_coder{
   int coder_id;
   pthread_t thread_id;
   t_dongel *left_dongle;
   t_dongel *right_dongle;
   long last_compiletime;
   int num_of_compiles;
   
} t_coder;

typedef struct s_status{
   long  start_time;
   int   stop;
   t_coder   *set_of_coders;
   t_dongel   *set_of_dongles;
   pthread_mutex_t print_mutex;
   char *scheduler_type;
   int num_of_coders;
}t_status;

#endif