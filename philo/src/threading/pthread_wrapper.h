/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:21:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/08 00:04:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_WRAPPER_H
# define PTHREAD_WRAPPER_H

# include "main.h"

int	init_simul(t_simul *simul);
int	init_simul_mutex_init(t_simul *simul);
int	init_simul_create(t_simul *simul);
int	init_simul_join(t_simul *simul);
int	init_simul_mutex_destroy(t_simul *simul);

#endif
