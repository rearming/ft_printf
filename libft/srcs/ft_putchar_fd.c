/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:53:13 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putchar_fd(char c, int fd)
{
	unsigned char	ch[2];

	if (c >= 0)
		write(fd, &c, 1);
	else
	{
		ch[0] = (3 << 6) + ((unsigned char)c >> 6);
		ch[1] = (1 << 7) + ((unsigned char)c & 63);
		write(fd, ch, 2);
	}
}
