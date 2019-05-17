/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:54:17 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/17 13:50:06 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_words(char *str, char delim)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delim)
			count++;
		i++;
	}
	if (i > 0 && str[i - 1] != delim)
		count++;
	return (count);
}

char		**split_flags(const char *str, char delim)
{
	size_t		start;
	size_t		end;
	int			i;
	int			words;
	char		**result;

	if (!str)
		return (NULL);
	words = count_words(str, delim);
	if (!(result = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	result[words] = 0;
	i = 0;
	start = 0;
	while (i < words)
	{
		end = 0;
		if (str[start] == delim && str[start + 1] == delim)
		{
			result[i] = ft_strdup("%");
			start += 1;
			i++;
		}
		if (str[start] == delim)
			start++;
		while (str[start + end] && str[start + end] != delim)
			end++;
		result[i++] = ft_strsub(str, start, end);
		start += end;
	}
	return (result);
}
