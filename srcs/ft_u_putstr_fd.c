/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:34:13 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/20 14:13:00 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_u_putchar_fd(char *c, int fd)
{
	write(fd, &c[0], 1);
	write(fd, &c[1], 1);
	write(fd, &c[2], 1);
	write(fd, &c[3], 1);
}

int			ft_u_putstr_fd(char *str, int fd)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i + 1] && str[i + 2]
					&& str[i + 3])
	{
		write(fd, &str[i], 1);
		write(fd, &str[i + 1], 1);
		write(fd, &str[i + 2], 1);
		write(fd, &str[i + 3], 1);
		i += 4;
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
