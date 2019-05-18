/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/18 21:17:41 by rearming         ###   ########.fr       */
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
	va_list		ap;
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
	print_list(g_printf.lst_buf);
	free_list(&g_printf.lst_buf);
	return (0);
}

int			main(void)
{
	printf("\n--------------------------------\n");
	printf("\t\tJust text:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("jopa lel kek%%%% ynolikpro|\n");
	printf("printf:    jopa lel kek%%%% ynolikpro|\n");

	printf("\n--------------------------------\n");
	printf("\t\tChar:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("%c\n", '&');
	printf("printf:    %c\n", '&');

	printf("\n--------------------------------\n");
	printf("\t\tString:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("zez%10.4s\n", "oooraa");
	printf("printf:    zez%10.4s\n", "oooraa");

	printf("\n--------------------------------\n");
	printf("\t\tInt:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("big precision %10.20i\n", 42);
	printf("printf:    big precision %10.20i\n", 42);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("small: %10.i\n", 4222);
	printf("printf:    small: %10.i\n", 4222);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("NO PREC: %10i\n", 4222);
	printf("printf:    NO PREC: %10i\n", 4222);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("min width: %2.i\n", 7777777);
	printf("printf:    min width: %2.i\n", 7777777);

	printf("\n--------------------------------\n");
	printf("\t\tConversion to char:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("big precision %10.20hhi\n", 22);
	printf("printf:    big precision %10.20hhi\n", 22);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("small: %10.hhi\n", 422222);
	printf("printf:    small: %10.hhi\n", 422222);

	printf("\n--------------------------------\n");
	printf("\t\tConversion to short:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("big precision %10.20hi\n", 42);
	printf("printf:    big precision %10.20hi\n", 42);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("small: %10.2hi\n", 88888);
	printf("printf:    small: %10.2hi\n", 88888);

	printf("\n--------------------------------\n");
	printf("\t\tLong:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("kek: %10.1li zezap\n", 30000l);
	printf("printf:    kek: %10.1li zezap\n", 30000l);

	printf("\n--------------------------------\n");
	printf("\t\tLong Long:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("ll: %10.1lli flex\n", 63333ll);
	printf("printf:    ll: %10.1lli flex\n", 63333ll);

	printf("\n--------------------------------\n");
	printf("\t\tUnsigned:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("obojau %10.0u\n", 999u);
	printf("printf:    obojau %10.0u\n", 999u);

	printf("\n--------------------------------\n");
	printf("\t\tUnsigned long:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("small kek: %10.2lu &&&$%%\n", 1018lu);
	printf("printf:    small kek: %10.2lu &&&$%%\n", 1018lu);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("big Mek: %4.10lu &&&$%%\n", 100010001000lu);
	printf("printf:    big Mek: %4.10lu &&&$%%\n", 100010001000lu);

	printf("\n--------------------------------\n");
	printf("\t\tUnsigned long long:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("small prec: %10.2llu &&&$%%\n", 1345llu);
	printf("printf:    small prec: %10.2llu &&&$%%\n", 1345llu);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("big prec: %10.5llu &&&$%%\n", 9889988888888888888llu);
	printf("printf:    big prec: %10.5llu &&&$%%\n", 9889988888888888888llu);

	printf("\n--------------------------------\n");
	printf("\t\tBig hex:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("long long HEX: %10llX &&&$%%\n", 922337203685477580ll);
	printf("printf:    long long HEX: %10llX &&&$%%\n", 922337203685477580ll);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("mini HEX: %10llX &&&$%%\n", 98ll);
	printf("printf:    mini HEX: %10llX &&&$%%\n", 98ll);

	printf("\n--------------------------------\n");
	printf("\t\tSmall hex:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("just hex: %#10x &&&$%%\n", 1535);
	printf("printf:    just hex: %#10x &&&$%%\n", 1535);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("just hex without grid: %10x &&&$%%\n", -9984);
	printf("printf:    just hex without grid: %10x &&&$%%\n", -9984);

	printf("\n--------------------------------\n");
	printf("\t\tOctal:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("robots: %#10llo &&&$%%\n", 666ll);
	printf("printf:    robots: %#10llo &&&$%%\n", 666ll);

	printf("\n--------------------------------\n");
	printf("\t\tPointer:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("robots: %p &&&$%%\n", &ft_printf);
	printf("printf:    robots: %p &&&$%%\n", &ft_printf);

	printf("\n--------------------------------\n");
	printf("\t\tBinary:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("robots: %#10b &&&$%%\n", 255);

	return (0);
}
