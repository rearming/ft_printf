/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:35:47 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/18 14:17:09 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_short(char *part, t_format format)
{

}

void		add_ushort(char *part, t_format format)
{

}

void		add_int(char *part, t_format format)
{
	char 	*arg;

	arg = ft_itoa(va_arg(g_printf.ap, int));
	
	fill_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i], ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_uint(char *part, t_format format)
{
	char 	*arg;

	arg = ft_itoa(va_arg(g_printf.ap, unsigned));
	fill_format(format, arg);
	free(arg);
	ft_lstaddback(&g_printf.lst_buf, &part[format.i], ft_strlen(&part[format.i]) + 1);
	free(part);
}