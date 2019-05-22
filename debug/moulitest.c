/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulitest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:43:56 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/22 20:30:18 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>

void		moulitest(void)
{
	printf("\n--------------------------------\n");
	write(1, "ft_printf: ", 11);
	ft_printf("{%5%}");
	ft_putchar('\n');
	printf("printf:    {%5%}");

	printf("\n--------------------------------\n");
	printf("\t\tSmall hex:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("just hex: %#10x &&&$%%\n", -1535);
	ft_putchar('\n');
	printf("printf:    just hex: %#10x &&&$%%\n", -1535);

	printf("\n--------------------------------\n");
	printf("\t\tPTR:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("%p", 0);
	ft_putchar('\n');
	printf("printf:    %p", 0);

	printf("\n--------------------------------\n");
	printf("\t\tOCTAL LONG_MAX:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("%O", LONG_MAX);
	ft_putchar('\n');
	printf("printf:    %O", LONG_MAX);

	printf("\n--------------------------------\n");
	printf("\t\tSpace with int:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("% 10i\n", 42);
	ft_putchar('\n');
	printf("printf:    % 10i\n", 42);

}