/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_philos_eaten_enough.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:47:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:17:44 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Parses the struct of each philo to check if all meals_left are <= 0
** @param:	- [t_simul *] base struct of the program
** @return:	[int] true or false
** Line-by-line comments:
** @4-5		If the value is -1 then it means that the argument was not provided
**			so philo have never eaten enough
** @10-14	If just one philo still has meals left to eat then we return 'false'
*/

int	have_philos_eaten_enough(t_simul *simul)
{
	int	check;
	int	i;

	if (simul->settings->nb_times_to_eat == -1)
		return (0);
	check = 1;
	i = 0;
	while (i < simul->settings->nb_philo)
	{
		if (simul->philos[i].meals_left > 0)
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
