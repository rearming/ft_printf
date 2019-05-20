/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 10:57:04 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

void		print_list(t_list *list, int fd)
{
	while (list)
	{
		ft_u_putstr_fd(list->content, fd);
		list = list->next;
	}
}

void		free_list(t_list **list)
{
	t_list		*temp;

	while (*list)
	{
		free((*list)->content);
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

void		add_buf_node(char *part)
{
	t_format	format;

	format = get_format(part);
	//print_format(format); //todo debug
	if (format.type_flag == BREAK || format.type == BREAK)
		add_text(part, format);
	if (format.type == CHAR)
		add_char(part, format);
	if (format.type == STRING)
		add_string(part, format);

	if (format.type == INT)
		add_signed(part, format);
	if (format.type == UNSIGNED)
		add_unsigned(part, format);
	if (format.type == B_HEX || format.type == S_HEX
		|| format.type == PTR || format.type == OCTAL
			|| format.type == BINARY)
		add_base(part, format);
}

int 		ft_printf(const char *format, ...)
{
	int			i;
	char 		**parts;

	va_start(g_printf.ap, format);
	parts = split_flags(format, '%');
	i = 0;
	while (parts[i])
	{
		add_buf_node(parts[i]);
		i++;
	}
	va_end(g_printf.ap);
	print_list(g_printf.lst_buf, 1);
	free_list(&g_printf.lst_buf);
	return (0);
}
