/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:31:03 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/23 17:44:30 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_new;
	int		i;

	i = 0;
	if (s)
	{
		if (!(s_new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			s_new[i] = f((char)s[i]);
			i++;
		}
		s_new[i] = '\0';
		return (s_new);
	}
	return (NULL);
}
