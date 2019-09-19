/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:07:39 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/23 18:12:22 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	c;
	char	*str_new;

	if (!s)
		return (NULL);
	start = 0;
	c = 0;
	while ((s[start] == 32 || s[start] == 10 || s[start] == 9) && s[start] != 0)
	{
		start++;
		c++;
	}
	if (s[start] != '\0')
	{
		end = ft_strlen(s) - 1;
		while (s[end] == 32 || s[end] == '\n' || s[end] == '\t')
		{
			end--;
			c++;
		}
	}
	str_new = ft_strsub(s, start, ft_strlen(s) - c);
	return (str_new);
}
