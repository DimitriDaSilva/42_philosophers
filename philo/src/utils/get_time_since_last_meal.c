/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_since_last_meal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:26:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/06 17:40:57 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	get_time_since_last_meal(struct timeval *last_meal)
{
	struct timeval	curr_time;
	long			time_since_last_meal;

	gettimeofday(&curr_time, NULL);
	time_since_last_meal = get_time_diff(&curr_time, last_meal);
	return (time_since_last_meal);
}
