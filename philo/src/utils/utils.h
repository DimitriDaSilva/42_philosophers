/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:23:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 16:04:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "main.h"

# define STATUS_BUFFER 50

void	free_memory(t_philo *philo);
long	get_time_before_death(t_philo *philo, struct timeval *lastmeal);
long	get_time_diff(struct timeval *present, struct timeval *past);
long	get_time_since_last_meal(struct timeval *lastmeal);
char	*get_timestamp(struct timeval *curr_time,
			struct timeval *program_start);
int		have_philos_eaten_enough(t_philo *simulation);
int		print_status(t_philo *philo, int index, char *status);

#endif
