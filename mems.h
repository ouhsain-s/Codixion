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

typedef struct s_dongle{
   pthread_mutex_t   mutex;
   pthread_cond_t      cond; 
   long last_release_time;
   t_queue *priority_queue;
}t_dongle;

typedef struct s_coder{
   int coder_id;
   pthread_t thread_id;
   t_dongle *left_dongle;
   t_dongle *right_dongle;
   long last_compile_time;
   int num_of_compiles;

} t_coder;

typedef struct s_status{
   long  start_time;
   int   stop;
   t_coder   *set_of_coders;
   t_dongle   *set_of_dongles;
   pthread_mutex_t print_mutex;
   char *scheduler_type;
   t_configs   *session_conf;
}t_status;

typedef struct s_thread_args{
   t_status    *status;
   int         current_id;
}t_thrad_args;


#endif