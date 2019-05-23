/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:20:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/22 19:57:42 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		shift_arg(char **arg)
{
	size_t	i;

	i = 0;
	while ((*arg)[i + 1])
	{
		(*arg)[i] = (*arg)[i + 1];
		i++;
	}
	(*arg)[i] = 0;
}

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

char		*add_prefix(char *arg, t_format *format)
{
	if (!arg)
		return (0);
	if (arg[0] == '-')
	{
		shift_arg(&arg);
		format->width--;
		return (ft_strdup("-"));
	}
	if (format->flags.plus)
	{
		if (format->flags.space && (ft_isdigit(arg[0])))
			return (ft_strdup(" +"));
		else
			return (ft_strdup("+"));
	}
	if (format->flags.space)
	{
		format->width--;
		return (ft_strdup(" "));
	}
	return (0);
}

char		*add_base_prefix(char *arg, t_format *format)
{
	if (!arg)
		return (0);
	if ((format->flags.grid && ft_atoll_base(arg, 16)) || format->type == PTR)
	{
		format->width -= format->type == OCTAL ? 1 : 2;
		if (format->type == S_HEX || format->type == PTR)
			return (ft_strdup("0x"));
		if (format->type == B_HEX)
			return (ft_strdup("0X"));
		if (format->type == OCTAL)
			return (ft_strdup("0"));
	}
	return (0);
}

void		fill_int_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;
	char		*prefix;

	if (format.type != OCTAL && format.type != B_HEX
			&& format.type != S_HEX && format.type != PTR)
		prefix = add_prefix(arg, &format);
	else
		prefix = add_base_prefix(arg, &format);
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
	{
		if (!format.flags.zero && format.width > len)
		{
			fill_differ(differ, format);
			if (prefix)
				ft_lstaddback(&g_printf.lst_buf, prefix, ft_strlen(prefix) + 1);
		}
		else
		{
			if (prefix)
				ft_lstaddback(&g_printf.lst_buf, prefix, ft_strlen(prefix) + 1);
			fill_differ(differ, format);
		}
	}
	else
		if (prefix)
			ft_lstaddback(&g_printf.lst_buf, prefix, ft_strlen(prefix) + 1);
	ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	if (format.flags.minus)
		fill_differ(differ, format);
	free(temp);
	free(prefix);
}

void		fill_text_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	len = arg ? ft_strlen(arg) : 6;
	if (arg && !arg[0] && (format.type == CHAR))
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
	char 		*temp;

	if (!arg)
		return ;
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
	if (format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	fill_differ(differ, format);
	if (!format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, temp, len + 1);
	free(temp);
}
