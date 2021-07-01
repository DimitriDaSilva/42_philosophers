/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:01:37 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 12:30:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "main.h"

int	has_invalid_args(int argc, char *argv[]);
int	has_non_numeric_arg(int argc, char *argv[]);

#endif
