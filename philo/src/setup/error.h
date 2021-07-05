/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:19:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 12:19:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "main.h"

int	has_invalid_args(int argc, char *argv[]);
int	has_non_numeric_arg(int argc, char *argv[]);

#endif
