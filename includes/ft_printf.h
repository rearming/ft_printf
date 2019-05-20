/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:17:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 16:35:43 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# include "libft.h"
# include "structs.h"
# include "ft_types.h"

extern t_printf	g_printf;

/*
** main functions
*/

int 	ft_printf(const char *format, ...);

/*
** format parsing functions
*/

t_format	get_format(char *part);

/*
** string functions
*/

void		add_text(char *part);
void		add_string(char *part, t_format format);
void		add_char(char *part, t_format format);
void		add_uchar(char *part, t_format format);

/*
** whole number functions
*/

void		add_short(char *part, t_format format);
void		add_ushort(char *part, t_format format);
void		add_int(char *part, t_format format);
void		add_uint(char *part, t_format format);

/*
**	float, double & long double
*/
char		*check_fields(t_ld *ld);

#endif