/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:44:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 20:23:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAKE_RELEASE_FORKS_H
# define TAKE_RELEASE_FORKS_H

# include "main.h"

int	take_two_forks(t_simul *philo,
		int philo_index,
		int first_fork,
		int second_fork);
int	take_fork(t_simul *philo, int philo_index, int fork_index);
int	release_two_forks(t_simul *simul, int first_fork, int second_fork);
int	release_fork(t_simul *philo, int fork_index);

#endif
