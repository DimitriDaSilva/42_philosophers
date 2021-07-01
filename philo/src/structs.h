/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:13:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "main.h"

typedef struct s_settings
{
    int             nb_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nb_times_to_eat;
}                   t_settings;

// Fork states. 0 is fork_not_available & 1 is fork_available
typedef struct s_philo
{
    t_settings      *settings;
    pthread_t       *threads;
    pthread_mutex_t *forks;
    int             index;
}                   t_philo;

#endif
