/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:40:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 15:13:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_philo.h"

t_philo	*get_philo(int argc, char *argv[])
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (gettimeofday(&philo->program_start, NULL) != EXIT_SUCCESS)
		return (NULL);
	philo->settings = get_settings(argc, argv);
	if (!philo->settings)
		return (NULL);
	philo->philos = get_single_philos(philo->settings);
	if (!philo->settings)
		return (NULL);
	philo->threads = ft_calloc(philo->settings->nb_philo, sizeof(pthread_t));
	if (!philo->threads)
		return (NULL);
	philo->forks = ft_calloc(philo->settings->nb_philo,
			sizeof(pthread_mutex_t));
	if (!philo->forks)
		return (NULL);
	return (philo);
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

t_single_philo	*get_single_philos(t_settings *settings)
{
	t_single_philo	*philos;
	int				i;

	philos = ft_calloc(settings->nb_philo, sizeof(t_single_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < settings->nb_philo)
	{
		philos[i].index = i;
		philos[i].meals_left = settings->nb_times_to_eat;
		i++;
	}
	return (philos);
}
