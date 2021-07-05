/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_simul.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:41:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 17:57:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PHILO_H
# define GET_PHILO_H

# include "main.h"

t_simul			*setup_simul(int argc, char *argv[]);
t_settings		*get_settings(int argc, char *argv[]);
t_philo	*get_philos(t_settings *settings);

#endif
