/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:21:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 15:02:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_WRAPPER_H
# define PTHREAD_WRAPPER_H

# include "main.h"

int	init_philo(t_philo *philo);
int	init_philo_mutex_init(t_philo *philo);
int	init_philo_create(t_philo *philo);
int	init_philo_join(t_philo *philo);
int	init_philo_mutex_destroy(t_philo *philo);

#endif
