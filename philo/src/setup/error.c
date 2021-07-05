/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:00:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 12:24:48 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	has_invalid_args(int argc, char *argv[])
{
	int	check;

	if (argc != 5 && argc != 6)
		check = 1;
	else if (has_non_numeric_arg(argc, argv))
		check = 1;
	else
		check = 0;
	return (check);
	(void)argv;
}

int	has_non_numeric_arg(int argc, char *argv[])
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i < argc)
	{
		if (!ft_strisdigit(argv[i]))
		{
			check = 1;
			break ;
		}
		i++;
	}
	return (check);
}
