/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:57:54 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 19:32:26 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			my_tests(void)
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

	write(1, "ft_printf: ", 11);
	ft_printf("%+-010c\n", '&');
	printf("printf:    %+-010c\n", '&');

	printf("\n--------------------------------\n");
	printf("\t\tString:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("zez%10s\n", "string");
	printf("printf:    zez%10s\n", "string");

	write(1, "ft_printf: ", 11);
	ft_printf("plus string %+010.s\n", "oooraa");
	printf("printf:    plus string %+010.s\n", "oooraa");

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

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("min width: %+2.i\n", -7777777);
	printf("printf:    min width: %+2.i\n", -7777777);

	ft_putchar('\n');
	write(1, "ft_printf: ", 11);
	ft_printf("ZERO: %+2i\n", 0);
	printf("printf:    ZERO: %+2i\n", 0);

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
	ft_printf("kek: %+10.1li zezap\n", 30000l);
	printf("printf:    kek: %+10.1li zezap\n", 30000l);

	write(1, "ft_printf: ", 11);
	ft_printf("kek: %020.1li zezap\n", 30000l);
	printf("printf:    kek: %020.1li zezap\n", 30000l);

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

	write(1, "ft_printf: ", 11);
	ft_printf("PLUS %+10.0u\n", 999u);
	printf("printf:    PLUS %+10.0u\n", 999u);

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
	ft_printf("long long HEX: %+10llX &&&$%%\n", 922337203685477580ll);
	printf("printf:    long long HEX: %+10llX &&&$%%\n", 922337203685477580ll);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("mini HEX: [✅][❌] %10llX &&&$%% [✅][❌] \n", 98ll);
	printf("printf:    mini HEX: [✅][❌] %10llX &&&$%% [✅][❌] \n", 98ll);

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
	ft_printf("lel oct%%: %#+10llo &&&$%%\n", 666ll);
	printf("printf:    lel oct%%: %#10llo &&&$%%\n", 666ll);

	write(1, "ft_printf: ", 11);
	ft_printf("octal no #: %+10llo &&&$%%\n", 666ll);
	printf("printf:    octal no #: %+10llo &&&$%%\n", 666ll);

	printf("\n--------------------------------\n");
	printf("\t\tPointer:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("robots: %p &&&$%%\n", &ft_printf);
	printf("printf:    robots: %p &&&$%%\n", &ft_printf);

	printf("\n--------------------------------\n");
	printf("\t\tBinary:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("robots: %#10b &&&$%%\n", 255);

	printf("\n--------------------------------\n");
	printf("\t\tFloat:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("lel float%%: %#+10f &&&$%%\n", (float)666.123123);
	printf("printf:    lel float%%: %#+10f &&&$%%\n", (float)666.123123);

	printf("\n--------------------------------\n");
	printf("\t\tDouble:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("NO prec#: %+10.0f &&&$%%\n", (double)5662.1345111);
	printf("printf:    NO prec#: %+10.0f &&&$%%\n", (double)5662.1345111);

	ft_putchar('\n');

	write(1, "ft_printf: ", 11);
	ft_printf("Dobble prec#: %+10.3f &&&$%%\n", (double)5662.1345111);
	printf("printf:    Dobble prec#: %+10.3f &&&$%%\n", (double)5662.1345111);

	printf("\n--------------------------------\n");
	printf("\t\tLong double:\n\n");

	write(1, "ft_printf: ", 11);
	ft_printf("SUPER LONG D: %Lf &&&$%%\n", 1243132.1343524L);
	printf("printf:    SUPER LONG D: %Lf &&&$%%\n", 1243132.1343524L);
}