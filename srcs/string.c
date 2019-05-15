/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:20:52 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/14 17:30:40 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

void		add_text(char *part)
{
	ft_lstaddback(&g_printf.lst_buf, part, ft_strlen(part));
	free(part);
}

void		add_string(char *part, t_format format)
{

}

void		add_char(char *part, t_format format)
{

}

void		add_uchar(char *part, t_format format)
{

}