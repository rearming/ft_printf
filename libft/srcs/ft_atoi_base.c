/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:19:09 by rearming          #+#    #+#             */
/*   Updated: 2019/05/10 21:14:00 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_obs(char *str, int *is_neg)
{
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		*is_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	return (i);
}

long		ft_atoi_base(char *str, int base)
{
	int		i;
	int		is_neg;
	long	res;
	int		digits;

	res = 0;
	is_neg = 1;
	i = skip_obs(str, &is_neg);
	if (base > 16 || base < 2)
		return (0);
	digits = count_digits_base(&str[i], base) - 1;
	while (ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'A' + base - 11))
	{
		if (ft_isdigit(str[i]) && str[i] > '0' + base)
			return (res * is_neg);
		if (ft_isdigit(str[i]))
			res += (str[i] - '0') * ft_power(base, digits);
		else
			res += (str[i] - 55) * ft_power(base, digits);
		i++;
		digits--;
	}
	return (res * is_neg);
}
