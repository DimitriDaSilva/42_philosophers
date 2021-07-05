/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:20:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 12:20:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LIFE_H
# define INIT_LIFE_H

# include "main.h"

void	*init_life(void *arg);
int		start_taking_forks(t_philo *philo, int index, struct timeval *lastmeal);
int		start_eating(t_philo *philo, int index, struct timeval *lastmeal);
int		start_sleeping(t_philo *philo, int index, struct timeval *lastmeal);
int		start_thinking(t_philo *philo, int index);
int		take_fork(t_philo *philo, int philo_index, int fork_index);
int		release_fork(t_philo *philo, int fork_index);

#endif
