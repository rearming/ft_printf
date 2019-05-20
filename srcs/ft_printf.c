/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 15:26:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

int			print_list(t_list **list, int fd)
{
	int		total_printed;
	t_list	*temp;

	total_printed = 0;
	if (!list)
		raise_error(ERR_NULL_LIST);

	size_t 	total_len;
	t_list	*tmp_count;
	char 	*buffer;
	int 	new_start;

	fd = 1;
	tmp_count = *list;
	total_len = 0;
	new_start = 0;
	while (tmp_count)
	{
		total_len += tmp_count->content_size - 1;
		tmp_count = tmp_count->next;
	}
	buffer = (char*)malloc(sizeof(char) * (total_len + 1));
	while (*list)
	{
		//total_printed += ft_u_putstr_fd((*list)->content, fd);
		//total_printed += printf("%s", (*list)->content);
		/*if ((*list)->content)
			total_printed += write(1, ((*list)->content), (*list)->content_size - 1);*/
		ft_memcpy(&buffer[new_start], (*list)->content, (*list)->content_size - 1);
		new_start += (*list)->content_size - 1;
		temp = (*list);
		(*list) = (*list)->next;
		free(temp->content);
		free(temp);
	}
	write(fd, buffer, total_len);
	return (total_printed);
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
	int 		ret_val;

	va_start(g_printf.ap, format);
	parts = split_flags(format, '%');
	i = 0;
	while (parts[i])
	{
		add_buf_node(parts[i]);
		i++;
	}
	va_end(g_printf.ap);
	ret_val = print_list(&g_printf.lst_buf, 1);
	//free_list(&g_printf.lst_buf);
	return (ret_val);
}
