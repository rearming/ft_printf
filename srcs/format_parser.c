/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:28:42 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/14 18:51:21 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		i++;
	}
	if (flags.plus || flags.minus)
		flags.space = 0;
	return (flags);
}

int 		get_width(char *part, int *i)
{
	int 	res;

	if (part[*i] == '*')
		return (va_arg(g_printf.ap, int));
	if (!ft_isdigit(part[*i]))
		return (0);
	res = ft_atoi(&part[*i]);
	*i = ft_count_digits(res); //todo check later
	return (res);
}

int 		get_accuracy(char *part, int *i)
{
	int		res;

	if (part[*i] != '.')
		return (NOT_SET);
	(*i)++;
	if (part[*i] == '*')
		return (va_arg(g_printf.ap, int));
	res = ft_atoi(&part[*i]);
	*i = count_digits(res);
	return (res);
}

int 		get_type(char *part, int *i)
{
	while (!ft_isalpha(part[*i]))
		(*i)++;
	
	if (part[*i] == 'c')

}

t_format	get_format(char *part)
{
	t_format	format;
	int 		i;

	i = 0;
	format.flags = get_flags(part, &i);
	format.width = get_width(part, &i);
	format.accuracy = get_accuracy(part, &i);
	format.type =
}