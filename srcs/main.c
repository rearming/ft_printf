/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/14 17:32:51 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char 	*parse_arg()
{
	//ft_lstadd_b(, parse_arg(), );
}

char 	is_type(char *arg)
{

}*/

void	add_buf_node(char *part)
{
	t_format	format;

	format = get_format(part);
	if (format.type == NOTHING)
		add_text(part);
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

/*int		print_result(void)
{

}*/

int 	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char 		**parts;

	i = 0;
	va_start(g_printf.ap, format);
	parts = ft_strsplit(format, '%');
	while(parts[i])
	{
		add_buf_node(parts[i]);
		i++;
	}
	va_end(g_printf.ap);
	return (0);
	//return (print_result());
}

int		main(void)
{
	//ft_printf("%i\n", 10);
	return (0);
}
