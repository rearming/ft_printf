/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:30:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 20:01:27 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void		int_prec_tests(void)
{
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%#08x", 42);
	ft_putchar('\n');
	printf("printf:    %#08x", 42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%0+10d", 42);
	ft_putchar('\n');
	printf("printf:    %0+10d", 42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%5d", -42);
	ft_putchar('\n');
	printf("printf:    %5d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%0+5d", -42);
	ft_putchar('\n');
	printf("printf:    % 0+5d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("% 12.5d", 4242);
	ft_putchar('\n');
	printf("printf:    % 12.5d", 4242);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%03.2d", -1);
	ft_putchar('\n');
	printf("printf:    %03.2d", -1);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %.10d", -42);
	ft_putchar('\n');
	printf("printf:    @moulitest: %.10d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %.5u", 42);
	ft_putchar('\n');
	printf("printf:    @moulitest: %.5u", 42);
	printf("\n");
}
