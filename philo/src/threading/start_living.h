/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_living.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:20:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 15:27:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LIFE_H
# define INIT_LIFE_H

# include "main.h"

void	*start_living(void *arg);
int		start_taking_forks(t_philo *philo, t_single_philo *single_philo);
int		start_eating(t_philo *philo, t_single_philo *single_philo);
int		start_sleeping(t_philo *philo, t_single_philo *single_philo);
int		start_thinking(t_philo *philo, t_single_philo *single_philo);
int		take_fork(t_philo *philo, int philo_index, int fork_index);
int		release_fork(t_philo *philo, int fork_index);

#endif
