/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:17:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 16:03:27 by sleonard         ###   ########.fr       */
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

int 					ft_printf(const char *format, ...);
void					add_buf_node(char *part);
void					free_list(t_list **list);

/*
** output functions
*/

char 					*get_buffer(t_list **list, size_t total_len);
int						print_list(t_list **list, int fd);

/*
** format parsing functions
*/

t_flags					get_flags(char *part, int *i);
int						get_width(char *part, int *i);
int						get_precision(char *part, int *i);
int						get_type_flag(char *part, int *i);
int						get_type(char *part, int *i);
t_format				get_format(char *part);

/*
** formatting functions
*/

void					fill_int_format(t_format format, char *arg);
void					fill_format(t_format format, char *arg);
void					fill_float_format(t_format format, char *arg);
void					fill_differ(int differ, t_format format);
void					fill_base_format(t_format format, char *arg);
void					fill_text_format(t_format format, char *arg);

/*
** string functions
*/

void					add_text(char *part, t_format format);
void					add_string(char *part, t_format format);
void					add_char(char *part, t_format format);
void					add_percent(char *part, t_format format);

/*
** int functions
*/

char 					*convert_signed_arg(t_format format);
void					add_signed(char *part, t_format format);
void					add_unsigned(char *part, t_format format);
void					add_base(char *part, t_format format);

/*
** debug functions
*/

void					print_format(t_format format);
char 					*debug_type(int code);
void					my_tests(void);
void					basic_tests(void);

/*
** error functions
*/

void					raise_error(int err_code);

/*
** split flags function
*/

char					**split_flags(const char *str, char delim);

/*
** itoa and atoi's
*/

char					*ft_lltoa(long long n);
char					*ft_ulltoa(unsigned long long int n);
char					*ft_lltoa_base(long long nbr, int base, char capital, char format);
long long				ft_atoll(char *str);
unsigned long long 		ft_atoull(const char *str);
char					*ft_ulltoa_base(unsigned long long nbr, int base, char capital, char format);

/*
**	float, double & long double
*/

char					*check_fields(t_ld *ld);
void					add_double(char *part, t_format format);

#endif