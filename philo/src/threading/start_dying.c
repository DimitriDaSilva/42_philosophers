/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:17:49 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:05:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_dying.h"

/*
** When start_dying() is called we know that he either won't have enough time
** to wait around for available forks or that his sleep will be his last. So we
** just need to wait the time_before_death time before printing that he died
** @param:	- [t_simul *] base struct of the program
**			- [int] philo index. 0 based index
**			- [int] philo's fork to grab. 0 based index
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @4-6		That will let other philos know that a philo is dead and that the
**			simulation needs to stop
*/

int	start_dying(t_simul *simul, int philo_index, int time_before_death)
{
	usleep(time_before_death * 1000);
	if (print_status(simul, philo_index + 1, "died") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&simul->death_lock);
	simul->has_a_philo_died = 1;
	pthread_mutex_unlock(&simul->death_lock);
	return (EXIT_SUCCESS);
}
