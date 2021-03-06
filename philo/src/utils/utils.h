/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:23:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 23:55:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "main.h"

# define STATUS_BUFFER 50

void	free_memory(t_simul *simul);
long	get_time_before_death(t_simul *simul, struct timeval *last_meal);
long	get_time_diff(struct timeval *present, struct timeval *past);
long	get_time_since_last_meal(struct timeval *last_meal);
char	*get_timestamp(struct timeval *program_start);
int		have_philos_eaten_enough(t_simul *simul);
int		is_philo_about_to_die(t_simul *simul, t_philo *philo);
int		print_status(t_simul *simul, int index, char *status);
int		will_get_forks_on_time(t_simul *simul, t_philo *philo);

#endif
