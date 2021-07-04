/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:23:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/04 11:53:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "main.h"

# define STATUS_BUFFER 50

int	        print_status(t_philo *philo, int index, char *status);
char        *get_timestamp(struct timeval *curr_time, struct timeval *program_start);
long	    get_time_diff(struct timeval *present, struct timeval *past);
long	    get_time_before_death(t_philo *philo, struct timeval *lastmeal);
long        get_time_since_last_meal(struct timeval *lastmeal);

#endif
