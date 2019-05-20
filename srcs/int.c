/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:35:47 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 10:56:17 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_signed_arg(t_format format)
{
	if (format.type_flag == NOT_SET)
		return (ft_lltoa(va_arg(g_printf.ap, int)));
	if (format.type_flag == CHAR)
		return (ft_lltoa((char)va_arg(g_printf.ap, int)));
	if (format.type_flag == SHORT)
		return (ft_lltoa((short)va_arg(g_printf.ap, int)));
	if (format.type_flag == LONG)
	{
		//print_format(format);
		return (ft_lltoa(va_arg(g_printf.ap, long)));
	}
	if (format.type_flag == LONG_LONG)
		return (ft_lltoa(va_arg(g_printf.ap, long long)));
	return (NULL);
}

char		*convert_unsigned_arg(t_format format)
{
	if (format.type == PTR)
		return (ft_ulltoa(va_arg(g_printf.ap, unsigned long long)));
	if (format.type_flag == NOT_SET)
		return (ft_ulltoa(va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == CHAR)
		return (ft_ulltoa((unsigned char)va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == SHORT)
		return (ft_ulltoa((unsigned short)va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == LONG)
		return (ft_ulltoa(va_arg(g_printf.ap, unsigned long)));
	if (format.type_flag == LONG_LONG)
		return (ft_ulltoa(va_arg(g_printf.ap, unsigned long long)));
	return (NULL);
}

void		add_signed(char *part, t_format format)
{
	char	*arg;

	format.flags.zero =
			format.precision != NOT_SET ? 0 : format.flags.zero;
	format.precision = format.precision == NOT_SET ? 0 : format.precision;
	arg = convert_signed_arg(format);
	ft_isdigit(arg[0]) && format.flags.plus ? format.width -= 1 : format.width;
	fill_int_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_unsigned(char *part, t_format format)
{
	char	*arg;

	format.precision = format.precision == NOT_SET ? 0 : format.precision;
	arg = convert_unsigned_arg(format);
	if (format.precision % 10 == 0 && format.precision != 0)
	{
		format.flags.zero = 1;
		format.width = format.precision;
	}
	format.precision = ft_strlen(arg);
	fill_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_base(char *part, t_format format)
{
	char	*arg;

	format.flags.zero =
			format.precision != NOT_SET ? 0 : format.flags.zero;
	format.flags.plus = 0;
	format.precision = format.precision == NOT_SET ? 0 : format.precision;
	arg = convert_unsigned_arg(format);
	if (format.type == B_HEX || format.type == S_HEX || format.type == PTR)
		arg = ft_lltoa_base(ft_atoll(arg), 16, format.type == B_HEX ? 1 : 0,
				format.flags.grid || format.type == PTR ? 1 : 0);
	else
		arg = ft_lltoa_base(ft_atoll(arg),
				format.type == BINARY ? 2 : 8, 0, format.flags.grid ? 1 : 0);
	fill_int_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}
