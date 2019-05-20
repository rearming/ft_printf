/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:26:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/20 17:29:54 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structs.h"
#include <stdio.h>
#include <limits.h>

static t_ld				*parse_ld(long double num, int precision)
{
	__int128_t			mask;
	long				whole;
	long				fract;
	t_ld				*ld;

	if (!(ld = (t_ld*)malloc(sizeof(t_ld))))
		return (NULL);
	ld->str = NULL;
	ld->ld.ld_tmp = num;
	mask = (__int128_t)0x7FFF << 64;
	ld->exp = (int)((ld->ld.int_tmp & mask) >> 64);
	mask = (__int128_t)1 << 73;
	ld->negative = (int)((ld->ld.int_tmp & mask) >> 73);
	if (check_fields(ld))
		return (ld);
	whole = (long)num;
	fract = (ft_power(10, precision) * (long)num) - whole;
	return (ld);
}

static char				*lftoa(long double num, int precision)
{
	char				*a;
	t_ld				*ld;

	a = NULL;
	ld = parse_ld(num, precision);
	if (precision <= 0)
		precision = 6;
	return (a);
}

int						main(void)
{
	long double				num;
	char					*a;

	num = 123.123L;
	a = lftoa(num, 6);
	printf("%Lf\n", num);
	return (0);
}
