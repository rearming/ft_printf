/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:07:51 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/21 16:07:51 by sleonard         ###   ########.fr       */
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
