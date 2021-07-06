/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:51:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 17:12:48 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_memory(t_simul *simul)
{
	free(simul->philos);
	free(simul->settings);
	free(simul->threads);
	free(simul->forks);
	free(simul);
}
