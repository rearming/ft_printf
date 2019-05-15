/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:26:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/15 14:05:44 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char					*get_double(double num, int after)
{
	unsigned long		lpart;
	double				dpart;
	size_t				pos;
	char				*lline;
	char				*dline;

	lpart = (unsigned long)num;
	dpart = num - (double)lpart;
	lline = ft_itoa((int)lpart);
	pos = ft_strlen(lline);
	lline[pos++] = '.';
	if (after != 0)
	{
		dpart = dpart * ft_power(10, after);
		dline = ft_itoa((int)dpart);
		lline = ft_strcat(lline, dline);
	}
	return (lline);
}

int						main(void)
{
	double				num;

	num = 15234523455.34523452345;
	printf("%s\n", get_double(num, 3));
	return (0);
}
