/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/17 14:36:33 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

void		print_list(t_list *list)
{
	while (list)
	{
		ft_u_putstr_fd(list->content, 1);
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
	if (format.type == UCHAR)
		add_uchar(part, format);
	if (format.type == STRING)
		add_string(part, format);

	if (format.type == SHORT)
		add_short(part, format);
	if (format.type == USHORT)
		add_ushort(part, format);
	if (format.type == INT)
		add_int(part, format);
	if (format.type == UINT)
		add_uint(part, format);
}

int 		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char 		**parts;

	va_start(g_printf.ap, format);
	parts = split_flags(format, '%');
	ft_lstaddback(&g_printf.lst_buf, parts[0], ft_strlen(parts[0]));
	i = 1;
	while (parts[i])
	{
		if (parts[i][0])
		{
			if (parts[i][0] == '%' && !parts[i][1])
			{
				ft_lstaddback(&g_printf.lst_buf, parts[i], ft_strlen(parts[i]));
				ft_lstaddback(&g_printf.lst_buf, parts[i + 1], ft_strlen(parts[i + 1]));
				i++;
			}
			else
				add_buf_node(parts[i]);
		}
		i++;
	}
	va_end(g_printf.ap);
	print_list(g_printf.lst_buf);
	free_list(&g_printf.lst_buf);
	return (0);
}

int			main(void)
{
	printf("\n--------------------------------\n");
	printf("\t\tJust text:\n\n");

	write(1, "ft_printf: ", 11);

	ft_printf("jopa lel kek%%%% ynolikpro|\n"); //todo handle % (пробела нет потому что это якобы флаг)
	printf("printf:    jopa lel kek%%%% ynolikpro|\n");


	printf("\n--------------------------------\n");
	printf("\t\tChar:\n\n");

	ft_printf("ft_printf: %c\n", '&');
	printf("printf:    %c\n", '&');

	printf("\n--------------------------------\n");
	printf("\t\tString:\n\n");

	write(1, "ft_printf: ", 11);

	ft_printf("zez%10.4s\n", "ooor");
	printf("printf:    zez%10.4s\n", "ooor");

	printf("\n--------------------------------\n");
	printf("\t\tInt:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("zez%10.4i\n", 42);

	printf("printf:    zez%10.4i\n", 42);

	return (0);
}
