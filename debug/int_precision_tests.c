/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:30:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/22 19:42:15 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

//todo list addr ...782040

void		int_prec_tests(void)
{
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("hekko %#08x", 42);
	ft_putchar('\n');
	printf("printf:    hekko %#08x", 42);

	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("ptrr %p", &write);
	ft_putchar('\n');
	printf("printf:    ptrr %p", &write);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%0+10d", 42);
	ft_putchar('\n');
	printf("printf:    %0+10d", 42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%7.3d", -42);
	ft_putchar('\n');
	printf("printf:    %7.3d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%0+5d", -42);
	ft_putchar('\n');
	printf("printf:    %0+5d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%-+12.5d", 5050);
	ft_putchar('\n');
	printf("printf:    %-+12.5d", 5050);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("%03.2d", -1);
	ft_putchar('\n');
	printf("printf:    %03.2d", -1);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("no width: %.10d", -42);
	ft_putchar('\n');
	printf("printf:    no width: %.10d", -42);

	printf("\n");
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("UNSIGNED: %.5u", 42);
	ft_putchar('\n');
	printf("printf:    UNSIGNED: %.5u", 42);
	printf("\n");
}
