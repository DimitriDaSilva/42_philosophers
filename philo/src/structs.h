/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:23:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 08:56:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

typedef struct s_philo
{
	int				index;
	struct timeval	last_meal;
	int				meals_left;
	int				has_had_first_meal;
}					t_philo;

typedef struct s_settings
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
}					t_settings;

typedef struct s_simul
{
	t_philo			*philos;
	t_settings		*settings;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	increment_lock;
	pthread_mutex_t	meals_left_lock;
	pthread_mutex_t	death_lock;
	int				has_a_philo_died;
	struct timeval	prog_start;
}					t_simul;

#endif
