/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:17:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/16 18:04:20 by sleonard         ###   ########.fr       */
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
# include "error.h"

extern t_printf	g_printf;

/*
** main functions
*/

int 		ft_printf(const char *format, ...);
int			ft_printf_fd(const char *format, int fd, ...);

/*
** format parsing functions
*/

t_format	get_format(char *part);

/*
** formatting functions
*/

void fill_format(t_format format, char *arg);

/*
** string functions
*/

void		add_text(char *part, t_format format);
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
** debug functions
*/

void		print_format(t_format format);

/*
** error functions
*/

void		raise_error(int err_code);

/*
** unicode functions
*/

void		ft_u_putchar_fd(char *c, int fd);
void		ft_u_putstr_fd(char *str, int fd);

/*
** split flags function
*/

char 	**split_flags(const char *str, char delim);

#endif