/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:42:01 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/06 17:42:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIGHT_H
# define LIBFT_LIGHT_H

# include "main.h"

# define ASCII_OFFSET_NUM 48
# define STATUS_BUFFER 50

long long	ft_abs(long long n);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_is_even(long long nb);
char		*ft_itoa(long long n);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strisdigit(char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
size_t		get_len_int(long long nb);

#endif
