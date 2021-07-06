/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:23:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 14:33:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

/*
** Each philosopher is represented by a t_philo struct
** @fields:
** [int index] index of the philosopher in the simul->threads array. Start at 0
** but it gets one added to it once it's printed
** [struct timeval last_meal] each time the philo eats it saves the timestamp
** [int meals_left] if nb_times_to_eat argument is not set, meals_left = -1
** [int has_had_first_meal] tracks if philosophers has already ate
*/

typedef struct s_philo
{
	int				index;
	struct timeval	last_meal;
	int				meals_left;
	int				has_had_first_meal;
}					t_philo;

/*
** Command line arguments
** @fields:
** [int nb_philo] number of philosophers and also the number of forks
** [int time_to_die] in milliseconds. If a philosopher doesn’t start eating
** X ms after starting his last meal or the beginning of the simulation,
** it dies
** [int time_to_eat] in milliseconds. Time it takes for a philosopher to eat.
** During that time he will need to keep the two fork
** [int time_to_sleep] s in milliseconds. Time the philo will spend sleeping
** [int nb_times_to_eat] optional arg. If all philosophers eat at least X 
** times the simulation will stop. If not specified, the simulation will stop
** only at the death of a philosopher
*/

typedef struct s_settings
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
}					t_settings;

/*
** Base struct of the program
** @fields:
** [t_philo *philos] array of t_philo. Each item represents a living
** philosophers
** [t_settings *settings] struct with command line arguments
** [pthread_t *threads] array of threads
** [pthread_mutex_t *forks] array of mutex dedicated to locking forks
** [pthread_mutex_t increment_lock] mutex used to manage write access to a var
** used to assign a single philo to a thread
** [pthread_mutex_t meal_left_lock] locks var meal_left in each t_philo item
** [pthread_mutex_t death_lock] locks var has_a_philo_died in t_simul
** [int has_a_philo_died] true or false. Prevents printing once a philo died
** and leads all threads to terminate
** [struct timeval prog_start] struct used by gettimeofday. Here saves the start
** of the program
*/

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
