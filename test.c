/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:49:30 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 18:23:06 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <ulimit.h>
#include <float.h>

#include "ft_printf.h"
#include <tgmath.h>
#include <limits.h>

int 		new_count(const char *str, char delim);

int 	main(void)
{
	char 	*str = "hey %a%b%c%%%brother ";
	char 	*str2 = "%%privet%010i%%%c-zopa%";
	char 	**res;
	int 	i;

	i = 0;
	//printf("%#10.4hhx\n", 255);
/*	ft_printf("ptr: [%20p]\n", &i);
	ft_printf("int ptr: [%20o]\n", 255);
	ft_printf("hex: [%#lx]\n", &i);

	printf("ptr: [%20p]\n", &i);
	printf("int ptr: [%20o]\n", 255);
	printf("hex: [%#lx]\n", &i);*/

	float			num1 = 123.123456;
	double			num2 = 123.123456;
	long double 	num3 = 123.123456L;

	printf("float: [%f]\n", num1);
	printf("double: [%f]\n", num1);
	printf("long double: [%Li]\n", 2156551651LL);
	return (0);
}

//todo dev hint

/*types:

%c - char
%s - string
%p - pointer = %lx по сути

%d - int
%i - int
%o - octal
%u - unsigned
%x - hex (small, ff)
%X - hex (big, FF)

%f - double

with the following flags:

conversion to:

hh - char/unsigned char
h - short / unsigned short
l - long
ll - long long
L - long long / long double*/
