#ifndef MEMS_H
#define MEMS_H

typedef struct args_t{
   int number_of_coders = 0;
   int time_to_burnout = 0;
   int time_to_compile = 0;
   int time_to_debug = 0;
   int time_to_refactor = 0;
   int number_of_compiles_required = 0;
   int dongle_cooldown = 0;
   char *scheduler = "";
} configs_t

#endif