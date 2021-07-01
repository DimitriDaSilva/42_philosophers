/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:40:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:52 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_philo.h"

t_philo *get_philo(int argc, char *argv[])
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->settings = get_settings(argc, argv);
	philo->threads = ft_calloc(philo->settings->nb_philo, sizeof(pthread_t));
	if (!philo->threads)
		return (NULL);
	philo->forks = ft_calloc(philo->settings->nb_philo, sizeof(pthread_mutex_t));
	if (!philo->forks)
		return (NULL);
	return (philo);
}

t_settings *get_settings(int argc, char *argv[])
{
	t_settings *settings;

	settings = ft_calloc(1, sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->nb_philo = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]) * 1000;
	settings->time_to_eat = ft_atoi(argv[3]) * 1000;
	settings->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		settings->nb_times_to_eat = ft_atoi(argv[5]);
	else
		settings->nb_times_to_eat = -1;
	return (settings);
}
