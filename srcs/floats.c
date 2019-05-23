/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:26:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/23 11:40:54 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structs.h"
#include <stdio.h>
#include <limits.h>

static void			get_a(t_ld *ld, int sign,
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
	if (precision != 0)
	{
		ld->str = ft_strcat(ld->str, ".");
		ld->str = ft_strncat(ld->str, ft_ultoa(fract), (size_t)precision);
	}
}

static t_ld			*parse_ld(long double num, int precision)
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

static char			*ftoa(long double num, int precision)
{
	t_ld				*ld;

	if (precision == NO_FLAG)
		precision = 6;
	ld = parse_ld(num, precision);
	return (ld->str);
}

long double			get_doble_arg(t_format format)
{
	if (format.type_flag == LDOUBLE)
		return (va_arg(g_printf.ap, long double));
	return (va_arg(g_printf.ap, double));
}

void				fill_float_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	if (!arg)
		return ;
	len = ft_strlen(arg);
	differ = format.width > len ? format.width - len : 0;
	if (format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	}
	fill_differ(differ, format);
	if (!format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	}
}

void				add_double(char *part, t_format format)
{
	char	*arg;

	format.flags.zero =
			format.precision != NO_FLAG ? 0 : format.flags.zero;
	arg = ftoa(get_doble_arg(format), format.precision);
	format.precision = format.precision == NO_FLAG ? 0 : format.precision;
	ft_isdigit(arg[0]) && format.flags.plus ? format.width -= 1 : format.width;
	fill_float_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}
