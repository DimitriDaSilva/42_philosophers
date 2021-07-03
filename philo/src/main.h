/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:48:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 16:57:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>

# include "structs.h"
# include "get_philo.h"
# include "init_philo.h"
# include "init_life.h"
# include "error.h"
# include "utils.h"

void	free_memory(t_philo *philo);

#endif
