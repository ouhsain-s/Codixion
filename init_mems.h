/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mems.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:37 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 15:09:37 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MEMS_H
#define INIT_MEMS_H

#include "mems.h"

void	init_status(t_status *stat, t_configs *configs);
void	init_dongle(t_dongle *dongle);
void	init_coder(t_coder *coder, int id, t_dongle *r_d, t_dongle *l_d);

#endif