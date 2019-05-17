/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/16 15:52:41 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct			s_type
{
	char 				tp_char;
	unsigned char		tp_uchar;
	short 				tp_short;
	unsigned short		tp_ushort;
	int 				tp_int;
	unsigned int		tp_uint;
	long				tp_long;
	unsigned long 		tp_ulong;
	float 				tp_float;
	double				tp_double;
	long double			tp_l_double;
	char 				*string;
}						t_type;

typedef struct			s_flags
{
	char 				zero;
	char 				space;
	char 				grid;
	char 				plus;
	char 				minus;
}						t_flags;

typedef struct			s_format
{
	t_flags				flags;
	int 				width;
	int 				precision;
	int 				type_flag;
	int 				type;
	int 				i;
}						t_format;

typedef struct			s_printf
{
	t_list				*lst_buf;
	va_list 			ap;
}						t_printf;

#endif