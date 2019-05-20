/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:17:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 10:39:04 by sleonard         ###   ########.fr       */
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
int			print_list(t_list **list, int fd);
void		free_list(t_list **list);
void		add_buf_node(char *part);

/*
** format parsing functions
*/

t_format	get_format(char *part);

/*
** formatting functions
*/

void		fill_int_format(t_format format, char *arg);
void		fill_format(t_format format, char *arg);

/*
** string functions
*/

void		add_text(char *part, t_format format);
void		add_string(char *part, t_format format);
void		add_char(char *part, t_format format);

/*
** int functions
*/

char 		*convert_signed_arg(t_format format);
void		add_signed(char *part, t_format format);
void		add_unsigned(char *part, t_format format);
void		add_base(char *part, t_format format);

/*
** debug functions
*/

void		print_format(t_format format);
char 		*debug_type(int code);

/*
** error functions
*/

void		raise_error(int err_code);

/*
** unicode functions
*/

void		ft_u_putchar_fd(char *c, int fd);
int ft_u_putstr_fd(char *str, int fd);

/*
** split flags function
*/

char		**split_flags(const char *str, char delim);

/*
** itoa and atoi's
*/

char		*ft_lltoa(long long n);
char		*ft_ulltoa(unsigned long long int n);
char		*ft_lltoa_base(long long nbr, int base, char capital, char format);
long long	ft_atoll(char *str);

#endif