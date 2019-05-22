/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:11:20 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_ultoa(unsigned long n)
{
	int						qt;
	unsigned long			num;
	char					*res;

	num = n;
	qt = 1;
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
