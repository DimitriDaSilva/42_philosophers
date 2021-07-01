/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:44:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 20:28:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PHILO_H
# define INIT_PHILO_H

# include "main.h"

int init_philo(t_philo *philo);
int	init_philo_mutex_init(t_philo *philo);
int	init_philo_create(t_philo *philo);
int	init_philo_join(t_philo *philo);
int	init_philo_mutex_destroy(t_philo *philo);

#endif