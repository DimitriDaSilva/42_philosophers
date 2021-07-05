/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:51:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 17:10:56 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_memory(t_philo *philo)
{
	free(philo->philos);
	free(philo->settings);
	free(philo->threads);
	free(philo->forks);
	free(philo);
}