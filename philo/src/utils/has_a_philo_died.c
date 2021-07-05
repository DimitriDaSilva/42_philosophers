/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_a_philo_died.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:14:04 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 18:16:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	has_a_philo_died(t_simul *simul)
{
	int	check;

	pthread_mutex_lock(&simul->death_lock);
	if (simul->has_a_philo_died == 1)
		check = 1;
	else
		check = 0;
	pthread_mutex_unlock(&simul->death_lock);
	return (check);
}
