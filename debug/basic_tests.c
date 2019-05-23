/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:30:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 12:42:12 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void		basic_tests(void)
{
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi");
	ft_putchar('\n');
	printf("printf:    %s %s %s %s string. gg!", "this", "is", "a", "multi");

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %c zeza", 0);
	ft_putchar('\n');
	printf("printf:    @moulitest: %c zeza", 0);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%lld", -9223372036854775808);
	ft_putchar('\n');
	printf("printf:    %lld", -9223372036854775808);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%jd", -9223372036854775808);
	ft_putchar('\n');
	printf("printf:    %jd", -9223372036854775808);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%c", L'✅');
	ft_putchar('\n');
	printf("printf:    %c", L'✅');
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%s %s", NULL, "string");
	ft_putchar('\n');
	printf("printf:    %s %s", NULL, "string");

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%-5%");
	ft_putchar('\n');
	printf("printf:    %-5%");

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %#x %#0x", 0, 255);
	ft_putchar('\n');
	printf("printf:    @moulitest: %#x %#0x", 0, 255);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@INT: %.i %.0i", 1, 1);
	ft_putchar('\n');
	printf("printf:    @INT: %.i %.0i", 1, 1);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("negative prec: int : %0i unsg: %.u %03.1i", 0, 0, 36568);
	ft_putchar('\n');
	printf("printf:    negative prec: int : %0i unsg: %.u %03.1i", 0, 0, 36568);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %#x %#0x", 0, 255);
	ft_putchar('\n');
	printf("printf:    @moulitest: %#x %#0x", 0, 255);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ft_putchar('\n');
	printf("printf:    @moulitest: %#.x %#.0x", 0, 0);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@octal: %#.o %#.0o", 0, 0);
	ft_putchar('\n');
	printf("printf:    @octal: %#.o %#.0o", 0, 0);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("{%f}kekes\n", -1444565444646.1);
	ft_putchar('\n');
	printf("printf:    {%f}{%F}", -1444565444646.1, -1444565444646.6465424242242454654);
}
