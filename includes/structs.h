/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/14 18:06:23 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_arg
{
	char 				a_char;
	unsigned char		a_uchar;
	short 				a_short;
	unsigned short		a_ushort;
	int 				a_int;
	unsigned int		a_uint;
	long				a_long;
	unsigned long 		a_ulong;
	float 				a_float;
	double				a_double;
	long double			a_l_double;
	char 				*string;
}						t_arg;

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

typedef struct	s_printf
{
	t_list				*lst_buf;
	int 				end_i;
	__darwin_va_list	ap;
}				t_printf;

#endif