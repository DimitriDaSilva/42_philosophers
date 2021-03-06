/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:51:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:11:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Get time difference between two timeval struct in milliseconds
** @param:	- [struct timeval *] present. So a in (a - b)
**			- [struct timeval *] past. So b in (a - b)
** @return:	[long] time difference in ms
*/

long	get_time_diff(struct timeval *present, struct timeval *past)
{
	long	time_microseconds;
	long	time_milliseconds;

	time_microseconds = (long)((
				(present->tv_sec - past->tv_sec) * 1000000
				+ (long)present->tv_usec - (long)past->tv_usec));
	time_milliseconds = time_microseconds / 1000;
	return (time_milliseconds);
}
