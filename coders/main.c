#include "parsing_attr.h"

int main(int argc, char **argv){
    if (argc != 9)
        return 1

    int number_of_coders = get_num_of_coders(argc[1])
    int time_to_burnout = get_time(argc[2])
    int time_to_compile = get_time(argc[3])
    int time_to_debug = get_time(argc[4])
    int time_to_refactor = get_time(argc[5])
    int number_of_compiles_required = atoi(argc[6])
    int dongle_cooldown = atoi(argc[7])
    char *scheduler = get_scheduler(argc[8])

}