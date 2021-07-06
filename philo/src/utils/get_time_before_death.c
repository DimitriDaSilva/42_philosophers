/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_before_death.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:52:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 17:13:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	get_time_before_death(t_simul *simul, struct timeval *last_meal)
{
	long	time_before_death;
	int		time_to_die;
	int		time_since_last_meal;

	time_to_die = simul->settings->time_to_die;
	time_since_last_meal = get_time_since_last_meal(last_meal);
	time_before_death = time_to_die - time_since_last_meal;
	return (time_before_death);
}
