/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:25:44 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}
