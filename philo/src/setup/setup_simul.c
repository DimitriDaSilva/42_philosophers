/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_simul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:40:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 14:38:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_simul.h"

/*
** Readies the main struct of the program
** @param:	- [int] arg count
**			- [char **] argv values
** @return:	[int] exit status
** Line-by-line comments:
** @6-7		We need to keep track of when in time the program has started for
**			the timestamps (time in ms since beginning of the program)
** @11-13	Get an array of t_philo. Each item represents a philo
*/

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
	simul->philos = get_philos(simul->settings);
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

/*
** Gets the command line arguments
** @param:	- [int] arg count
**			- [char **] argv values
** @return:	[t_settings *] settings struct
*/

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

/*
** Get array of t_philo. One item per philo and we preset its values
** @param:	- [t_settings *] command line args
** @return:	[t_philo *] array of t_philo
*/

t_philo	*get_philos(t_settings *settings)
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
		philos[i].meals_left = settings->nb_times_to_eat;
		i++;
	}
	return (philos);
}
