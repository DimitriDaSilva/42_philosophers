/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:24:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/04 11:48:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_light.h"

size_t	get_len_int(long long nb)
{
	if (0 <= nb && nb < 10)
		return (1);
	else if (-10 < nb && nb < 0)
		return (2);
	return (1 + get_len_int(nb / 10));
}
