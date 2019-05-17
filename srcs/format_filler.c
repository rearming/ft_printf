/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:20:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/16 18:41:23 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_format(t_format format, char *arg)
{
	size_t		len;
	int			differ;
	char		*temp;

	if (!arg)
		raise_error(ERR_ARG);
	len = ft_strlen(arg);
	len = format.precision < len ? format.precision : len;
	differ = format.width > len ? format.width - len : 0;
	arg = ft_strsub(arg, 0, len);
	if (format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
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
	if (!format.flags.minus)
		ft_lstaddback(&g_printf.lst_buf, arg, len + 1);
}
