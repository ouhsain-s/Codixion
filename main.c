/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:53 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 16:49:09 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "codixion.h"
#include "mems.h"

int check_is_data_matched(t_configs	data){

	if (data.number_of_coders < 0)
		return 0;
	if (data.time_to_burnout < 0)
		return 0;
	if (data.time_to_compile < 0)
		return 0;
	if (data.time_to_debug < 0)
		return 0;
	if (data.time_to_refactor < 0)
		return 0;
	if (data.number_of_compiles < 0)
		return 0;
	if (data.dongle_cooldown < 0)
		return 0;
	if (data.scheduler_type[0] == '\0')
		return 0;
	return 1;
}

void print_configs(t_configs	args)
{
	printf("=== CONFIGS ===\n");
	printf("number_of_coders            : %d\n", args.number_of_coders);
	printf("time_to_burnout             : %d\n", args.time_to_burnout);
	printf("time_to_compile             : %d\n", args.time_to_compile);
	printf("time_to_debug               : %d\n", args.time_to_debug);
	printf("time_to_refactor            : %d\n", args.time_to_refactor);
	printf("number_of_compiles_required : %d\n", args.number_of_compiles);
	printf("dongle_cooldown             : %d\n", args.dongle_cooldown);
	printf("scheduler                   : %s\n", args.scheduler_type);
}

void get_validate_args(char	**argv, t_configs	*t_args)
{
	t_args->number_of_coders = get_num_of_coders(argv[1]);
	t_args->time_to_burnout = get_time(argv[2]);
	t_args->time_to_compile = get_time(argv[3]);
	t_args->time_to_debug = get_time(argv[4]);
	t_args->time_to_refactor = get_time(argv[5]);
	t_args->number_of_compiles = ft_atoi(argv[6]);
	t_args->dongle_cooldown = ft_atoi(argv[7]);
	t_args->scheduler_type = get_scheduler(argv[8]);
}

int main(int	argc, char	**argv){
	if (argc != 9){
		printf("%d", argc);
		return 1;
	}
	t_configs	args;
	get_validate_args(argv, &args);

	if (check_is_data_matched(args) == 0)
		return 1;
	start_simulation(&args);
	print_configs(args);
	return 0;
}