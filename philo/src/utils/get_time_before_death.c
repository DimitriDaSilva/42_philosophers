/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_before_death.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:52:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 14:53:40 by dda-silv         ###   ########.fr       */
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
