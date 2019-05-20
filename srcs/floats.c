/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:26:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/20 18:03:36 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structs.h"
#include <stdio.h>
#include <limits.h>

static void				get_a(t_ld *ld, int sign,
								long double num, int precision)
{
	unsigned long		whole;
	unsigned long		fract;

	whole = (unsigned long)num;
	fract = (unsigned long)(ft_power(10, precision) * (num - whole));
	if (sign == -1)
		ld->str = ft_strdup("-");
	else
		ld->str = ft_strnew(0);
	ld->str = ft_strcat(ld->str, ft_ultoa(whole));
	ld->str = ft_strcat(ld->str, ".");
	ld->str = ft_strncat(ld->str, ft_ultoa(fract), (size_t)precision);
}

static t_ld				*parse_ld(long double num, int precision)
{
	__int128_t			mask;
	int					sign;
	t_ld				*ld;

	num = (double)num;
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
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	get_a(ld, sign, num, precision);
	return (ld);
}

static char				*ftoa(long double num, int precision)
{
	char				*a;
	t_ld				*ld;

	a = NULL;
	if (precision == NOT_SET)
		precision = 6;
	ld = parse_ld(num, precision);
	return (ld->str);
}

int						main(void)
{
	long double				num;
	char					*a;

	num = 123456789.123456789;
	a = ftoa(num, 6);
	printf("%s\n", a);
	printf("%Lf\n", num);
	return (0);
}
