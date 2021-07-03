/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 10:44:51 by dda-silv         ###   ########.fr       */
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

int set_eat(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_eat);
	return (EXIT_SUCCESS);
}

int set_sleep(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is sleeping") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_sleep);
	return (EXIT_SUCCESS);
	(void)philo;
	(void)index;
}

int set_think(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	(void)philo;
	(void)index;
	return (EXIT_SUCCESS);
}
