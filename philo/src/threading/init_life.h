/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:59:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 11:40:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LIFE_H
# define INIT_LIFE_H

# include "main.h"

void    *init_life(void *arg);
int     set_eat(t_philo *philo, int index);
int     set_sleep(t_philo *philo, int index);
int     set_think(t_philo *philo, int index);
int     take_fork(t_philo *philo, int philo_index, int fork_index);
int     release_fork(t_philo *philo, int fork_index);

#endif
