/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 15:20:50 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

char 		*get_buffer(t_list **list, size_t total_len)
{
	char		*buffer;
	int			start;
	t_list		*temp;

	start = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (total_len + 1))))
		raise_error(ERR_MALLOC);
	while (*list)
	{
		ft_memcpy(&buffer[start], (*list)->content, (*list)->content_size - 1);
		start += (*list)->content_size - 1;
		temp = (*list);
		(*list) = (*list)->next;
		free(temp->content);
		free(temp);
	}
	return (buffer);
}

int			print_list(t_list **list, int fd)
{
	size_t 		total_len;
	t_list		*tmp_count;
	char 		*buffer;

	if (!list)
		raise_error(ERR_NULL_LIST);
	tmp_count = *list;
	total_len = 0;
	while (tmp_count)
	{
		total_len += tmp_count->content_size - 1;
		tmp_count = tmp_count->next;
	}
	buffer = get_buffer(&g_printf.lst_buf, total_len);
	write(fd, buffer, total_len);
	free(buffer);
	return (total_len);
}

void		add_buf_node(char *part)
{
	t_format	format;

	format = get_format(part);
	//print_format(format);
	if (format.type_flag == BREAK || format.type == BREAK)
		add_text(part, format);
	if (format.type == CHAR)
		add_char(part, format);
	if (format.type == STRING)
		add_string(part, format);
	if (format.type == PERCENT)
		add_percent(part, format);

	if (format.type == INT)
		add_signed(part, format);
	if (format.type == UNSIGNED)
		add_unsigned(part, format);
	if (format.type == DOUBLE)
		add_double(part, format);
	if (format.type == B_HEX || format.type == S_HEX
		|| format.type == PTR || format.type == OCTAL
			|| format.type == BINARY)
		add_base(part, format);
}

int 		ft_printf(const char *format, ...)
{
	int			i;
	//char		*perc_str;
	char 		**parts;
	int 		ret_val;

	va_start(g_printf.ap, format);
	parts = split_flags(format, '%');
	i = 0;
	//t_format	temp_f;
	while (parts[i])
	{
		/*if (parts[i][0] == '%' && parts[i + 1])
			temp_f = get_format(parts[i + 1]);
		if (parts[i][0] == '%' && temp_f.type == PERCENT) //todo handle percent specifier
		{
			perc_str = ft_strjoin(parts[i], parts[i + 1]);
			add_buf_node(perc_str);
			free(parts[i]);
			free(parts[i + 1]);
			i++;
		}
		else*/
			add_buf_node(parts[i]);
		i++;
	}
	va_end(g_printf.ap);
	ret_val = print_list(&g_printf.lst_buf, 1);
	free(parts);
	return (ret_val);
}
