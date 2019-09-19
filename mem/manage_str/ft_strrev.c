/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:42:48 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/18 20:43:24 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		b;
	char	*str_copy;

	b = 0;
	i = ft_strlen(str) - 1;
	if (!(str_copy = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[b])
	{
		str_copy[i] = str[b];
		i--;
		b++;
	}
	str_copy[b] = '\0';
	ft_strdel(&str);
	return (str_copy);
}
