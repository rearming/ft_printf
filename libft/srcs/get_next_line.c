/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:53:21 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_file(t_list **files, int fd)
{
	t_list	*file;

	file = *files;
	while (file)
	{
		if ((int)file->content_size == fd)
			return (file);
		file = file->next;
	}
	if (!(file = ft_lstnew("\0", 1)))
		return (NULL);
	file->content_size = fd;
	ft_lstadd(files, file);
	file = *files;
	return (file);
}

static int		main_cycle(int fd, char *buf, t_list *file)
{
	int		ret;
	char	*temp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = file->content;
		file->content = ft_strjoin(temp, buf);
		free(temp);
		if (!(file->content))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static int		check_last(t_list *file, char **line)
{
	char	*temp;
	char	*ptr;

	temp = file->content;
	ptr = ft_strchr(temp, '\n');
	if (ptr)
	{
		if (!(*line = ft_strsub(temp, 0, ptr - temp)))
			return (-1);
		if (!(file->content = ft_strsub(ptr, 1, ft_strlen(ptr))))
			return (-1);
		free(temp);
		return (1);
	}
	if (!(*line = ft_strdup(file->content)))
		return (-1);
	free(file->content);
	if (!(file->content = ft_memalloc(1)))
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*files;
	t_list				*file;
	char				buf[BUFF_SIZE + 1];
	int					ret;

	if (fd < 0 || fd == 1 || fd == 2 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	file = get_file(&files, fd);
	if (!(*line = ft_strnew(1)))
		return (-1);
	free(*line);
	ret = main_cycle(fd, buf, file);
	if (ret == -1)
		return (-1);
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	ret = check_last(file, line);
	if (ret == 1)
		return (1);
	return (-1);
}
