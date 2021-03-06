/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:52:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:13:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Gets a string with the time that passed since the beginning of the program
** @param:	- [struct timeval *] timestamp done when the program started
** @return:	[char *] timestamp in ms as a string (to be freed by caller)
*/

char	*get_timestamp(struct timeval *program_start)
{
	char			*timestamp_str;
	long			timestamp_int;
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != EXIT_SUCCESS)
		return (NULL);
	timestamp_int = get_time_diff(&curr_time, program_start);
	timestamp_str = ft_itoa(timestamp_int);
	if (!timestamp_str)
		return (NULL);
	return (timestamp_str);
}
