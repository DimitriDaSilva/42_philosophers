/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:23:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 16:07:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

typedef struct s_single_philo
{
	int				index;
	struct timeval	last_meal;
	int				meals_left;
}					t_single_philo;

typedef struct s_settings
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
}					t_settings;

typedef struct s_philo
{
	t_single_philo	*philos;
	t_settings		*settings;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	int				has_a_philo_died;
	struct timeval	program_start;
}					t_philo;

#endif
