/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:28:42 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/18 21:02:37 by rearming         ###   ########.fr       */
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
	flags.minus ? flags.zero = 0 : flags.zero;
	return (flags);
}

int			get_width(char *part, int *i)
{
	int		res;

	if (part[*i] == '*')
		return (va_arg(g_printf.ap, int));
	if (!ft_isdigit(part[*i]))
		return (BREAK);
	res = ft_atoi(&part[*i]);
	*i += ft_count_digits(res);
	return (res);
}

int			get_precision(char *part, int *i)
{
	int		res;

	if (part[*i] != '.')
		return (NOT_SET);
	(*i)++;
	if (part[*i] == '*')
		return (va_arg(g_printf.ap, int));
	res = ft_atoi(&part[*i]);
	if (!ft_isdigit(part[*i]))
		*i -= 1;
	*i += ft_count_digits(res);
	return (res);
}

int			get_type_flag(char *part, int *i)
{
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
	if (part[(*i)] == 'j')
		return (LONG);
	if (part[*i] == 'z')
		return (SIZE_T);
	if (part[*i] == 'L')
		return (LDOUBLE);
	if (part[*i] == 'c' || part[*i] == 's' || part[*i] == 'p'
	|| part[*i] == 'd' || part[*i] == 'i' || part[*i] == 'o'
	|| part[*i] == 'u' || part[*i] == 'x' || part[*i] == 'X'
	|| part[*i] == 'b')
		return (NOT_SET);
	else
		return (BREAK);
}

int			get_type(char *part, int *i)
{
	if (part[*i] == 'c')
		return (CHAR);
	if (part[*i] == 's')
		return (STRING);
	if (part[*i] == 'p')
		return (PTR);
	if (part[*i] == 'd' || part[*i] == 'i')
		return (INT);
	if (part[*i] == 'u')
		return (UNSIGNED);
	if (part[*i] == 'o')
		return (OCTAL);
	if (part[*i] == 'x')
		return (S_HEX);
	if (part[*i] == 'X')
		return (B_HEX);
	if (part[*i] == 'f')
		return (DOUBLE);
	if (part[*i] == 'b')
		return (BINARY);
	if (part[*i] == 'r')
		return (NON_PRINT);
	return (part[*i] == 'k' ? DATE : BREAK);
}

t_format	get_format(char *part)
{
	t_format	format;

	format.flags = (t_flags){0, 0, 0, 0, 0};
	format = (t_format){format.flags, 0, 0, 0, 0};
	if ((part[format.i + 1] && part[format.i] == '%'
		&& part[format.i + 1] == '%')
			|| (part[format.i] != '%'))
		return ((t_format)
				{format.flags, 0, 0, BREAK, BREAK,
	 				part[format.i + 1] == '%' ? 1 : 0});
	else
		format.i++;
	format.flags = get_flags(part, &format.i);
	format.width = get_width(part, &format.i);
	format.precision = get_precision(part, &format.i);
	if ((format.type_flag = get_type_flag(part, &format.i)) == BREAK)
		return (format);
	if (format.type_flag != NOT_SET)
		format.i++;
	if ((format.type = get_type(part, &format.i)) != BREAK)
		format.i++;
	return (format);
}
