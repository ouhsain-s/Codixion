#include "codixion.h"

int get_num_of_coders(char *num_coders){
    num = ft_atoi(num_coders);
    if(num > 20 || num < 1)
        return -1;
    return num;
}

int get_time(char *str_time){
    time = ft_atoi(str_time);
    if (time > 100000 || num < 0)
        return -1;
    return time
}

char *get_scheduler(char *type){
    return type;
}