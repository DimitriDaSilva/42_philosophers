/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:59:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 17:57:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LIFE_H
# define INIT_LIFE_H

# include "main.h"

void    *init_life(void *arg);
int     start_taking_forks(t_philo *philo, int index);
int     start_eating(t_philo *philo, int index);
int     start_sleeping(t_philo *philo, int index);
int     start_thinking(t_philo *philo, int index);
int     take_fork(t_philo *philo, int philo_index, int fork_index);
int     release_fork(t_philo *philo, int fork_index);
int	    is_philo_dead(t_philo *philo, int index, struct timeval time_last_meal);

#endif
