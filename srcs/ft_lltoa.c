/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:47:56 by rearming          #+#    #+#             */
/*   Updated: 2019/05/20 10:33:49 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_ulltoa(unsigned long long int n)
{
	unsigned long long	num;
	int					qt;
	char				*res;

	qt = 1;
	num = n;
	while (n / 10)
	{
		n = n / 10;
		qt++;
	}
	if (!(res = ft_strnew(qt)))
		return (NULL);
	while (qt-- >= 1)
	{
		res[qt] = num % 10 + '0';
		num = num / 10;
	}
	return (res);
}

char				*ft_lltoa(long long n)
{
	unsigned long long	num;
	int					qt;
	char				*res;
	int					sign;

	sign = n < 0 ? 1 : 0;
	num = n;
	num = num * (sign ? -1 : 1);
	qt = 1 + sign;
	while (n / 10)
	{
		n = n / 10;
		qt++;
	}
	if (!(res = ft_strnew(qt)))
		return (NULL);
	if (sign)
		res[0] = '-';
	while (qt-- >= 1 + sign)
	{
		res[qt] = num % 10 + '0';
		num = num / 10;
	}
	return (res);
}