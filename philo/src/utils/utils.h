/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:23:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 10:21:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "main.h"

# define ASCII_OFFSET_NUM 48
# define STATUS_BUFFER 50

long long	ft_abs(long long n);
long long	ft_atoi(const char *str);
void	    *ft_calloc(size_t nmemb, size_t size);
char	    *ft_itoa(long long n);
int	        ft_putchar(char c);
int	        ft_putstr(char *str);
int	        ft_strisdigit(char *s);
size_t	    ft_strlcat(char *dst, const char *src, size_t size);
size_t	    ft_strlcpy(char *dst, const char *src, size_t size);
size_t      ft_strlen(const char *s);
size_t	    get_len_int(long long nb);
int	        print_status(t_philo *philo, int index, char *status);

#endif
