/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:42:10 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/23 20:53:10 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	new_lst = NULL;
	if (lst)
	{
		if (!(new_lst = (t_list*)ft_memalloc(lst->content_size)))
		{
			ft_lstdel(&new_lst, &ft_del);
			return (NULL);
		}
		new_lst = f(lst);
		lst = lst->next;
		new_lst->next = ft_lstmap(lst, f);
	}
	return (new_lst);
}
