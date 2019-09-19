/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:29:53 by grochefo          #+#    #+#             */
/*   Updated: 2018/12/21 13:40:08 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cutline(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(new = ft_strnew(ft_strlen(str) - i)))
		return (NULL);
	if (str[i])
		ft_strcpy(new, &str[i + 1]);
	if (str)
		ft_strdel(&str);
	return (new);
}

static int		ft_checkline(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static t_list	*ft_manage_list(t_list *st, size_t fd)
{
	char	*buff;
	t_list	*new;

	new = NULL;
	while (st)
	{
		if (st->content_size == fd)
			return (st);
		if (!st->next)
			break ;
		st = st->next;
	}
	buff = ft_strnew(0);
	if (!(new = ft_lstnew(buff, fd)))
		return (NULL);
	ft_strdel(&buff);
	st ? st->next = new : 0;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	static t_list		*st = NULL;
	t_list				*sv;
	int					ret;

	sv = st;
	if (!BUFF_SIZE || !line || fd < 0 || read(fd, buff, 0)
		|| !(st = ft_manage_list(st, (size_t)fd)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) || ((char*)st->content)[0])
	{
		buff[ret] = '\0';
		if (ret != 0 && !(st->content = ft_strjoinplus(st->content, buff, 1)))
			return (-1);
		if ((ft_strchr(st->content, '\n')) || (!ret && ((char*)st->content)[0]))
		{
			if (!(*line = ft_strndup(st->content, ft_checkline(st->content))))
				return (-1);
			if (!(st->content = ft_cutline(st->content)))
				return (-1);
			sv ? st = sv : 0;
			return (1);
		}
	}
	return (0);
}
