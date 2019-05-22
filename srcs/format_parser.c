/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:28:42 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/22 20:40:42 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

t_flags		get_flags(char *part, int *i)
{
	t_flags		flags;

	flags = (t_flags){0, 0, 0, 0, 0};
	while (part[*i] == '0' || part[*i] == '-'
		|| part[*i] == '+' || part[*i] == ' '
		|| part[*i] == '#')
	{
		if (part[*i] == '0')
			flags.zero = 1;
		if (part[*i] == '-')
			flags.minus = 1;
		if (part[*i] == '+')
			flags.plus = 1;
		if (part[*i] == ' ')
			flags.space = 1;
		if (part[*i] == '#')
			flags.grid = 1;
		(*i)++;
	}
	flags.zero = flags.minus ? 0 : flags.zero;
	flags.space = flags.plus ? 0 : flags.space;
	return (flags);
}

int			get_width(char *part, int *i)
{
	int		res;

	if (part[*i] == '*')
	{
		(*i)++;
		return (va_arg(g_printf.ap, int));
	}
	if (!ft_isdigit(part[*i]))
		return (NO_VALUE);
	res = ft_atoi(&part[*i]);
	*i += ft_count_digits(res);
	return (res);
}

int			get_precision(char *part, int *i)
{
	int		res;

	if (part[*i] != '.')
		return (NO_FLAG);
	(*i)++;
	if (part[*i] == '*')
	{
		(*i)++;
		return (va_arg(g_printf.ap, int));
	}
	res = ft_atoi(&part[*i]);
	if (ft_isdigit(part[*i]))
		*i += ft_count_digits(res);
	return (res);
}

int			get_type_flag(char *part, int *i)
{
	if (part[(*i) + 1] == 'U' || part[(*i)] == 'U')
		return (LONG);
	if (part[(*i) + 1] == 'O' || part[(*i)] == 'O')
		return (LONG);
	if (part[*i] == 'l')
	{
		if (part[++(*i)] == 'l')
			return (LONG_LONG);
		else if (--(*i) || part[*i])
			return (LONG);
	}
	if (part[*i] == 'h')
	{
		if (part[++(*i)] == 'h')
			return (CHAR);
		else if (--(*i) || part[*i])
			return (SHORT);
	}
	if (part[*i] == 'L')
		return (LDOUBLE);
	if (part[*i] == 'z')
		return (LONG_LONG);
	if (part[*i] == 'j')
		return (INT_MAX);
	if (get_type(part, *i) != BREAK)
		return (NO_FLAG);
	else
		return (BREAK);
}

int			get_type(char *part, int i)
{
	if (part[i] == 'c' || part[i] == 'C')
		return (CHAR);
	if (part[i] == 'C')
		return (WCHAR);
	if (part[i] == 's' || part[i] == 'S')
		return (STRING);
	if (part[i] == 'p')
		return (PTR);
	if (part[i] == 'd' || part[i] == 'D' || part[i] == 'i')
		return (INT);
	if (part[i] == 'u'|| part[i] == 'U')
		return (UNSIGNED);
	if (part[i] == 'o' || part[i] == 'O')
		return (OCTAL);
	if (part[i] == 'x')
		return (S_HEX);
	if (part[i] == 'X')
		return (B_HEX);
	if (part[i] == 'f' || part[i] == 'F')
		return (DOUBLE);
	if (part[i] == 'b')
		return (BINARY);
	if (part[i] == 'r')
		return (NON_PRINT);
	if (part[i] == '%')
		return (PERCENT);
	return (part[i] == 'k' ? DATE : BREAK);
}

t_format	get_format(char *part)
{
	t_format	format;

	format.flags = (t_flags){0, 0, 0, 0, 0};
	format = (t_format){format.flags, 0, 0, 0, 0, 0};
	if (part[format.i] != '%')
		return ((t_format)
				{format.flags, 0, 0, BREAK, BREAK, 0});
	else
		format.i++;
	format.flags = get_flags(part, &format.i);
	format.width = get_width(part, &format.i);
	format.precision = get_precision(part, &format.i);
	if ((format.type_flag = get_type_flag(part, &format.i)) == BREAK)
		return (format);
	if (format.type_flag != NO_FLAG
		&& part[format.i] != 'U' && part[format.i] != 'O')
		//todo don't forget about this kostil'
		format.i++;
	if ((format.type = get_type(part, format.i)) != BREAK)
		format.i++;
	return (format);
}
