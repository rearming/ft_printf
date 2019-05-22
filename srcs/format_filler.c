/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:20:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 20:32:07 by sleonard         ###   ########.fr       */
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

int 		add_signs(char **arg, t_format format)
{
	char	*temp;
	int 	len;

	if (!arg)
		return (0);
	len = ft_strlen(*arg);
	if (format.flags.plus)
		ft_isdigit(arg[0][0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
	if (!ft_isdigit(arg[0][0]))
		ft_lstaddback(&g_printf.lst_buf, "-", 2);
	if (!ft_isdigit(arg[0][0]))
	{
		temp = (char*)malloc(sizeof(char) * (len + 1));
		ft_memcpy(&temp[0], &arg[0][1], len + 1);
		arg[0] = temp;
		return (1);
	}
	return (0);
}

void		fill_base_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;

	len = ft_strlen(arg);
	if (format.precision != NO_FLAG)
	{
		temp = ft_strnew(len < format.precision ? format.precision : len);
		ft_memcpy(&temp[len < format.precision ? format.precision - len : 0], arg, len);
		ft_memset(temp, '0', len < format.precision ? format.precision - len : 0);
		len = format.precision > len ? format.precision : len;
	}
	else
		temp = ft_strdup(arg);
	differ = format.width > len ? format.width - len : 0;
	if (!format.flags.minus)
		fill_differ(differ, format);
	if (format.flags.space && (ft_isdigit(arg[0])))
		ft_lstaddback(&g_printf.lst_buf, " ", 2);
	if (format.flags.plus)
		ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
	ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	if (format.flags.minus)
		fill_differ(differ, format);
	free(temp);
}

void		fill_int_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;

	len = ft_strlen(arg);
	if (format.precision != NO_FLAG)
	{
		temp = ft_strnew(len < format.precision ? format.precision : len);
		ft_memcpy(&temp[len < format.precision ? format.precision - len : 0], arg, len);
		ft_memset(temp, '0', len < format.precision ? format.precision - len : 0);
		len = format.precision > len ? format.precision : len;
	}
	else
		temp = ft_strdup(arg);
	differ = format.width > len ? format.width - len : 0;
	if (!format.flags.minus)
		fill_differ(differ, format);
	if (format.flags.space && (ft_isdigit(arg[0])))
		ft_lstaddback(&g_printf.lst_buf, " ", 2);
	if (format.flags.plus)
		ft_isdigit(arg[0]) ? ft_lstaddback(&g_printf.lst_buf, "+", 2) : 0;
	ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	if (format.flags.minus)
		fill_differ(differ, format);
	free(temp);
}

void		fill_text_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	len = arg ? ft_strlen(arg) : 6;
	if (arg && !arg[0] && format.type == CHAR)
		len = 1;
	if (format.type == STRING && format.precision != NO_FLAG && arg)
	{
		format.precision = format.precision == NO_VALUE ? 0 : format.precision;
		len = format.precision < len ? format.precision : len;
	}
	differ = format.width > len ? format.width - len : 0;
	if (arg && !arg[0])
		arg = ft_strdup("\0");
	else
		arg = arg ? ft_strsub(arg, 0, len) : ft_strdup("(null)");
	if (format.flags.minus && arg)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	fill_differ(differ, format);
	if (!format.flags.minus && arg)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
	free(arg);
}


void		fill_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	if (!arg)
		return ;
	len = ft_strlen(arg);
	format.precision = format.precision == NO_FLAG ? 0 : format.precision;
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
