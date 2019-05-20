/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:20:52 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 09:37:45 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

void		add_text(char *part, t_format format)
{
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_string(char *part, t_format format)
{
	fill_format(format, va_arg(g_printf.ap, char*));
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_char(char *part, t_format format)
{
	char	*res;
	char	arg;

	res = ft_strnew(1);
	arg = va_arg(g_printf.ap, int);
	res[0] = (char)arg;
	fill_format(format, res);
	free(res);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}
