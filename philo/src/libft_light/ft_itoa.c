/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:31:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/04 11:47:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_light.h"

char	*ft_itoa(long long n)
{
	char	*str;
	size_t	size_nbr;

	size_nbr = get_len_int(n);
	str = ft_calloc(size_nbr + 1, sizeof(char));
	if (!str)
		return (0);
	str += size_nbr - 1;
	while (size_nbr--)
	{
		if (n == LONG_MIN)
			*str-- = '8';
		else
			*str-- = ft_abs(n) % 10 + ASCII_OFFSET_NUM;
		if (-10 < n && n < 0)
		{
			*str-- = '-';
			break ;
		}
		n /= 10;
	}
	return (++str);
}
