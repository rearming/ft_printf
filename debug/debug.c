/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:05:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 13:11:06 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_printf;

char 		*debug_type(int code)
{
	switch (code)
	{
		case BREAK:
			return ("BREAK");
		case INT_MAX:
			return ("INT_MAX");
		case CHAR:
			return ("CHAR");
		case UCHAR:
			return ("UCHAR");
		case SHORT:
			return ("SHORT");
		case USHORT:
			return ("USHORT");
		case INT:
			return ("INT");
		case UNSIGNED:
			return ("UNSIGNED");
		case LONG:
			return ("LONG");
		case LONG_LONG:
			return ("LONG_LONG");
		case ULONG:
			return ("UNSIGNED LONG");
		case ULONG_LONG:
			return ("UNSIGNED LONG LONG");
		case DOUBLE:
			return ("DOUBLE");
		case LDOUBLE:
			return ("LONG DOUBLE");
		case SIZE_T:
			return ("SIZE_T");
		case STRING:
			return ("STRING");
		case PTR:
			return ("POINTER");
		case OCTAL:
			return ("OCTAL");
		case S_HEX:
			return ("SMALL HEX");
		case B_HEX:
			return ("BIG HEX");
		case BINARY:
			return ("BINARY");
		case DATE:
			return ("DATE");
		case NON_PRINT:
			return ("NON_PRINTABLE");
		case PERCENT:
			return ("PERCENT");
		case NO_FLAG:
			return ("NO_FLAG");
		case NO_VALUE:
			return ("NO_VALUE");
		default:
			return ("WTF???");
	}
}

void		print_format(t_format format)
{
	t_flags flags;

	flags = format.flags;
	printf("\n>>>>>>>>>>>>>PRINTING T_FORMAT<<<<<<<<<<<<<\n\n");
	printf("t_format flags:\n\n");
	printf("\tzero:  [%s]\n", 	flags.zero ? "✅" : "❌");
	printf("\tspace: [%s]\n", flags.space ? "✅" : "❌");
	printf("\tgrid:  [%s]\n", 	flags.grid ? "✅" : "❌");
	printf("\tplus:  [%s]\n", 	flags.plus ? "✅" : "❌");
	printf("\tminus: [%s]\n", flags.minus ? "✅" : "❌");
	printf("\n");
	printf("t_format fields:\n\n");
	printf("width:     [%s]\n", format.width == BREAK ? "BREAK" : ft_itoa(format.width));
	printf("precision: [%s]\n", format.precision == NO_FLAG || NO_VALUE ? debug_type(format.precision) : ft_itoa(format.precision));
	printf("type_flag: [%s] | [%i]\n", debug_type(format.type_flag), format.type_flag);
	printf("type:      [%s] | [%i]\n", debug_type(format.type), format.type);
	printf("i: [%i]\n", format.i);
	printf("\n");
}