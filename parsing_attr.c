/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_attr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:41 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 16:38:59 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_num_of_coders(char	*num_coders){
	int	num;

	num = ft_atoi(num_coders);
	if(num > 20 || num < 1)
		return -1;
	return num;
}

int get_time(char	*str_time){
	int	time;

	time = ft_atoi(str_time);
	if (time > 100000 || time < 1)
		return -1;
	return time;
}

char *get_scheduler(char	*type){
	return type;
}
1