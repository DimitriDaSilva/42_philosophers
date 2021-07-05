/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:47:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 17:55:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_simul	*simul;

	if (has_invalid_args(argc, argv))
	{
		ft_putstr_fd("Error: invalid arguments\n", STDERR_FILENO);
		return (1);
	}
	simul = setup_simul(argc, argv);
	if (!simul)
	{
		ft_putstr_fd("Error: could not get philo\n", STDERR_FILENO);
		return (2);
	}
	if (init_simul(simul) != EXIT_SUCCESS)
	{
		ft_putstr_fd("Error: pthread function returned exit_failure\n",
			STDERR_FILENO);
		return (3);
	}
	free_memory(simul);
	return (EXIT_SUCCESS);
}
