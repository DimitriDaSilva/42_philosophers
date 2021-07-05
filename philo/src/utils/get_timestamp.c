/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:52:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 12:28:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_timestamp(struct timeval *curr_time, struct timeval *program_start)
{
	char	*timestamp_str;
	long	timestamp_int;

	timestamp_int = get_time_diff(curr_time, program_start);
	timestamp_str = ft_itoa(timestamp_int);
	if (!timestamp_str)
		return (NULL);
	return (timestamp_str);
}
