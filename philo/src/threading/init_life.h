/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:59:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 20:30:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LIFE_H
# define INIT_LIFE_H

# include "main.h"

void    *init_life(void *arg);
void    set_eat(t_philo *philo, int index);
void    set_sleep(t_philo *philo, int index);
void    set_think(t_philo *philo, int index);

#endif
