/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:30:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 17:47:01 by sleonard         ###   ########.fr       */
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
	ft_printf("@moulitest: % .1i %#.1x", 0, 0);
	ft_putchar('\n');
	printf("printf:    @moulitest: % .1i %#.1x", 0, 0);

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
	ft_printf("@moulitest: %#o %#o", 0, 0);
	ft_putchar('\n');
	printf("printf:    @moulitest: %#o %#o", 0, 0);

	/*printf("\nTESTS\n");
	ft_printf("%.2147483648d\n", 1); // int max + 1
	ft_printf("%.9223372036854775807d\n", 1); // long max + 1
	ft_printf("%.18446744073709551616d\n", 1); // ulong max + 1*/
}
