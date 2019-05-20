/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 17:14:37 by sselusa          ###   ########.fr       */
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
	int 				accuracy;
	int 				type;
}						t_format;

typedef struct			s_printf
{
	t_list				*lst_buf;
	va_list 			ap;
}						t_printf;

union 					u_ld
{
	long double			ld_tmp;
	__int128_t			int_tmp;
};

typedef struct			s_ld
{
	union u_ld			ld;
	char				*str;
	int					exp;
	int					negative;
}						t_ld;

#endif