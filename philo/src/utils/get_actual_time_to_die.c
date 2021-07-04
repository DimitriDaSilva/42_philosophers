/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_actual_time_to_die.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:26:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/04 11:29:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	get_time_before_death(t_philo *philo, struct timeval *lastmeal)
{
	long	time_before_death;
	int		time_to_die;
	int		time_since_last_meal;

	time_to_die = philo->settings->time_to_die;
	time_since_last_meal = get_time_since_last_meal(lastmeal);
	time_before_death = time_to_die - time_since_last_meal;
	return (time_before_death);
}

long get_time_since_last_meal(struct timeval *lastmeal)
{
	struct timeval	curr_time;
	long			time_since_last_meal;

	gettimeofday(&curr_time, NULL);
	time_since_last_meal = get_time_diff(&curr_time, lastmeal);
	return (time_since_last_meal);
}
