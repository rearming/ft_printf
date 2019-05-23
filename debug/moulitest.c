/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulitest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:43:56 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 11:31:16 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>

void		moulitest(void)
{
	/*printf("\n--------------------------------\n");
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
*/
	printf("\n--------------------------------\n");
	printf("\t\tOctal prec no value and grid:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("@moulitest: %o %#.0o", 0, 0);
	ft_putchar('\n');
	printf("printf:    @moulitest: %o %#.0o", 0, 0);

	printf("\n--------------------------------\n");
	printf("\t\tPTR:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("%.0p, %.p", 0, 0);
	ft_putchar('\n');
	printf("printf:    %.0p, %.p", 0, 0);
}