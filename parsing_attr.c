/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_attr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:37 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 15:09:37 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codixion.h"

int	get_num_of_coders(char *num_coders)
{
	int	num;

	num = ft_atoi(num_coders);
	if (num > 20 || num < 1)
		return (-1);
	return (num);
}

int	get_time(char *str_time)
{
	int	t;

	t = ft_atoi(str_time);
	if (t > 100000 || t < 1)
		return (-1);
	return (t);
}

char	*get_scheduler(char *type)
{
	return (type);
}