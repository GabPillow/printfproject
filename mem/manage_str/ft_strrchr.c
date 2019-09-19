/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:12:10 by grochefo          #+#    #+#             */
/*   Updated: 2018/12/08 13:19:23 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			b = i;
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char*)str + i);
	else if (str[b] != c)
		return (NULL);
	return ((char *)str + b);
}
