/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 20:41:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_life.h"

void	*init_life(void *arg)
{
	t_philo *philo;
	int		index;

	philo = (t_philo *)arg;
	index = philo->index++;
	set_eat(philo, index);
	set_sleep(philo, index);
	set_think(philo, index);
	return (NULL);
}

void set_eat(t_philo *philo, int index)
{
	usleep(philo->settings->time_to_eat);
	(void)philo;
	(void)index;
}

void set_sleep(t_philo *philo, int index)
{
	usleep(philo->settings->time_to_sleep);
	(void)philo;
	(void)index;
}

void set_think(t_philo *philo, int index)
{
	(void)philo;
	(void)index;
}
