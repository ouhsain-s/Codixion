/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecyckel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:17:26 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/23 10:57:17 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mems.h"

void    *coder_routine(void	*arg){
	t_thrad_args	*t_args;
	t_status		*status;
	t_coder			*coder;

	t_args = (t_thrad_args *)arg;
	status = t_args->status;
	coder = &status->set_of_coders[t_args->current_id];
			
	while (coder->num_of_compiles < 2)
	{
		
	}
	
	return NULL;
}