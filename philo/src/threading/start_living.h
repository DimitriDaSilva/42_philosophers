/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_living.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:20:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/08 00:06:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_LIVING_H
# define START_LIVING_H

# include "main.h"

void	*start_living(void *arg);
int		start_taking_forks(t_simul *simul, t_philo *philo);
int		start_eating(t_simul *simul, t_philo *philo);
int		start_sleeping(t_simul *simul, t_philo *philo);
int		start_thinking(t_simul *simul, t_philo *philo);

#endif
