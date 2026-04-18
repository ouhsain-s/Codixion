#include "codixion.h"
#include "mems.h"

int check_is_data_matched(configs_t data){
    if (data.num_coders > 0)
        return 0;
    if (data.number_of_coders > 0)
        return 0;
    if (data.time_to_burnout > 0)
        return 0;
    if (data.time_to_compile > 0)
        return 0;
    if (data.time_to_debug > 0)
        return 0;
    if (data.time_to_refactor > 0)
        return 0;
    if (data.number_of_compiles_required > 0)
        return 0;
    if (data.dongle_cooldown > 0)
        return 0;
    if (data.scheduler == "")
        return 0;
    return 1
}
int main(int argc, char **argv){
    if (argc != 9)
        return 1
    configs_t args;
    args.num_coders
    args.number_of_coders = get_num_of_coders(argc[1])
    args.time_to_burnout = get_time(argc[2])
    args.time_to_compile = get_time(argc[3])
    args.time_to_debug = get_time(argc[4])
    args.time_to_refactor = get_time(argc[5])
    args.number_of_compiles_required = ft_atoi(argc[6])
    args.dongle_cooldown = ft_atoi(argc[7])
    args.scheduler = get_scheduler(argc[8])

    check_is_data_matched(args)
}