/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_simul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:40:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 09:24:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_simul.h"

t_simul	*setup_simul(int argc, char *argv[])
{
	t_simul	*simul;

	simul = ft_calloc(1, sizeof(t_simul));
	if (!simul)
		return (NULL);
	if (gettimeofday(&simul->prog_start, NULL) != EXIT_SUCCESS)
		return (NULL);
	simul->settings = get_settings(argc, argv);
	if (!simul->settings)
		return (NULL);
	simul->philos = get_philos(simul->settings, &simul->prog_start);
	if (!simul->settings)
		return (NULL);
	simul->threads = ft_calloc(simul->settings->nb_philo, sizeof(pthread_t));
	if (!simul->threads)
		return (NULL);
	simul->forks = ft_calloc(simul->settings->nb_philo,
			sizeof(pthread_mutex_t));
	if (!simul->forks)
		return (NULL);
	return (simul);
}

t_settings	*get_settings(int argc, char *argv[])
{
	t_settings	*settings;

	settings = ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->nb_philo = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		settings->nb_times_to_eat = ft_atoi(argv[5]);
	else
		settings->nb_times_to_eat = -1;
	return (settings);
}

t_philo	*get_philos(t_settings *settings, struct timeval *prog_start)
{
	t_philo	*philos;
	int		i;

	philos = ft_calloc(settings->nb_philo, sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < settings->nb_philo)
	{
		philos[i].index = i;
		philos[i].last_meal = *prog_start;
		philos[i].meals_left = settings->nb_times_to_eat;
		i++;
	}
	return (philos);
}
