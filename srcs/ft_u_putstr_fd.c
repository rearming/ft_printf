/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:34:13 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/16 18:35:40 by sleonard         ###   ########.fr       */
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

void		ft_u_putstr_fd(char *str, int fd)
{
	size_t		i;
	size_t		len;

	i = 0;
	if (!str)
		return ;
	len = ft_strlen(str);
	while (str[i] && len > 4)
	{
		ft_u_putchar_fd(&(str[i]), fd);
		i += 4;
		len -= 4;
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
