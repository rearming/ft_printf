/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:20:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 10:20:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_differ(int differ, t_format format)
{
	char	*temp;

	if (differ)
	{
		temp = ft_strnew(differ);
		if (format.flags.zero)
			ft_memset(temp, '0', differ);
		else
			ft_memset(temp, ' ', differ);
		ft_lstaddback(&g_printf.lst_buf, temp, differ + 1);
		free(temp);
	}
}

void		fill_int_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;

	!arg ? raise_error(ERR_NULL_STR) : arg;
	len = ft_strlen(arg);
	temp = ft_strnew(len < format.precision ? format.precision : len);
	ft_memset(temp, '0', len < format.precision ? format.precision - len : 0);
	ft_strcpy(&temp[len < format.precision ? format.precision - len : 0], arg);
	len = format.precision > len ? format.precision : len;
	differ = format.width > len ? format.width - len : 0;
	if (format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
		ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	}
	fill_differ(differ, format);
	if (!format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
		ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	}
	free(temp);
}

void		fill_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	if (!arg)
		raise_error(ERR_ARG);
	len = ft_strlen(arg);
	len = format.precision < len ? format.precision : len;
	differ = format.width > len ? format.width - len : 0;
	arg = ft_strsub(arg, 0, len);
	if (format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	fill_differ(differ, format);
	if (!format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	free(arg);
}