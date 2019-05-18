/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:35:47 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/18 18:23:52 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 		*convert_signed_arg(t_format format)
{
	if (format.type_flag == NOT_SET)
		return (ft_lltoa(va_arg(g_printf.ap, int)));
	if (format.type_flag == CHAR)
		return (ft_lltoa((char)va_arg(g_printf.ap, int)));
	if (format.type_flag == SHORT)
		return (ft_lltoa((short)va_arg(g_printf.ap, int)));
	if (format.type_flag == LONG)
		return (ft_lltoa(va_arg(g_printf.ap, long)));
	if (format.type_flag == LONG_LONG)
		return (ft_lltoa(va_arg(g_printf.ap, long long)));
	return (NULL);
}

char 		*convert_unsigned_arg(t_format format)
{
	if (format.type_flag == NOT_SET)
		return (ft_lltoa(va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == CHAR)
		return (ft_lltoa((char)va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == SHORT)
		return (ft_lltoa((short)va_arg(g_printf.ap, unsigned)));
	if (format.type_flag == LONG)
		return (ft_lltoa(va_arg(g_printf.ap, unsigned long)));
	if (format.type_flag == LONG_LONG)
		return (ft_lltoa(va_arg(g_printf.ap, unsigned long long)));
	return (NULL);
}

void		add_signed(char *part, t_format format)
{
	char 	*arg;

	format.precision = format.precision == NOT_SET ? 0 : format.precision;
	arg = convert_signed_arg(format);
	fill_int_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i], ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_unsigned(char *part, t_format format)
{
	char 	*arg;

	format.precision = format.precision == NOT_SET ? 0 : format.precision;
	arg = convert_unsigned_arg(format);
	if (format.precision % 10 == 0 && format.precision != 0) //todo precision не работет с unsigned в оригинале, любые нули идут в флаг
	{
		format.flags.zero = 1;
		format.width = format.precision;
	}
	format.precision = ft_strlen(arg);
	fill_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i], ft_strlen(&part[format.i]) + 1);
	free(part);
}