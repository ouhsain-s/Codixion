#ifndef MEMS_H
#define MEMS_H

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

#endif