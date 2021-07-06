/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_simul.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:41:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 11:46:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_SIMUL_H
# define SETUP_SIMUL_H

# include "main.h"

t_simul			*setup_simul(int argc, char *argv[]);
t_settings		*get_settings(int argc, char *argv[]);
t_philo			*get_philos(t_settings *settings, struct timeval *prog_start);

#endif
