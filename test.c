/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:49:30 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/17 10:45:32 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <ulimit.h>
#include <float.h>

#include "ft_printf.h"
#include <tgmath.h>
#include <limits.h>

int 	main(void)
{
	char 	*str = "hey %a%b%c%%%brother ";
	char 	**res;
	int 	i;

	i = 0;
	//res = ft_strsplit(str, '%');
	res = split_flags(str, '%');
	while (res[i])
	{
		printf("res: [%s]\n", res[i]);
		i++;
	}
	return (0);
}

//todo dev hint

/*types:

%c - char
%s - string
%p - pointer

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
