/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 08:26:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_life.h"

void	*init_life(void *arg)
{
	t_philo *philo;
	int		index;

	philo = (t_philo *)arg;
	index = philo->index++;
	printf("Philosophers %d is about to sleep %.1f sec\n",
			index, (float)(philo->settings->time_to_sleep / 1000000));
	usleep(philo->settings->time_to_sleep);
	printf("Philosophers %d is done sleeping\n", index);
	/*set_eat(philo, index);*/
	/*set_sleep(philo, index);*/
	/*set_think(philo, index);*/
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
