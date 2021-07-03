/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:52:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 17:52:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char *get_timestamp(struct timeval curr_time, struct timeval program_start)
{
	char	*timestamp_str;
	long	timestamp_microseconds;
	long	timestamp_milliseconds;

	timestamp_microseconds = (long)((
				(curr_time.tv_sec - program_start.tv_sec) * 1000000
				+ (long)curr_time.tv_usec - (long)program_start.tv_usec));
	timestamp_milliseconds = timestamp_microseconds / 1000;
	timestamp_str = ft_itoa(timestamp_milliseconds);
	if (!timestamp_str)
		return (NULL);
	return (timestamp_str);
}
