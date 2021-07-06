/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:44:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 12:04:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAKE_RELEASE_FORKS_H
# define TAKE_RELEASE_FORKS_H

# include "main.h"

int	start_taking_forks(t_simul *philo, t_philo *single_philo);
int	is_philo_about_to_die(t_simul *philo, t_philo *single_philo);
int	take_two_forks(t_simul *philo,
		int philo_index,
		int first_fork,
		int second_fork);
int	take_fork(t_simul *philo, int philo_index, int fork_index);
int	release_fork(t_simul *philo, int fork_index);

#endif
