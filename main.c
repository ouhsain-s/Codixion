#include "codixion.h"
#include "mems.h"

int check_is_data_matched(configs_t data){

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
    if (data.scheduler[0] == '\0')
        return 0;
    return 1;
}

void print_configs(configs_t args)
{
    printf("=== CONFIGS ===\n");
    printf("number_of_coders            : %d\n", args.number_of_coders);
    printf("time_to_burnout             : %d\n", args.time_to_burnout);
    printf("time_to_compile             : %d\n", args.time_to_compile);
    printf("time_to_debug               : %d\n", args.time_to_debug);
    printf("time_to_refactor            : %d\n", args.time_to_refactor);
    printf("number_of_compiles_required : %d\n", args.number_of_compiles_required);
    printf("dongle_cooldown             : %d\n", args.dongle_cooldown);
    printf("scheduler                   : %s\n", args.scheduler);
}

int main(int argc, char **argv){
    if (argc != 9){
        printf("%d", argc);
        return 1;
    }
    configs_t args;
    args.number_of_coders = get_num_of_coders(argv[1]);
    args.time_to_burnout = get_time(argv[2]);
    args.time_to_compile = get_time(argv[3]);
    args.time_to_debug = get_time(argv[4]);
    args.time_to_refactor = get_time(argv[5]);
    args.number_of_compiles_required = ft_atoi(argv[6]);
    args.dongle_cooldown = ft_atoi(argv[7]);
    args.scheduler = get_scheduler(argv[8]);

    if (!check_is_data_matched(args))
        return 1;

    print_configs(args);
}