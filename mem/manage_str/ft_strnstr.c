/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:31:33 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/22 15:24:18 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t i;
	size_t b;

	i = 0;
	if (small[0] == '\0')
		return ((char*)big);
	while (i < n && big[i])
	{
		b = 0;
		while (big[i] == small[b] && i < n)
		{
			i++;
			b++;
			if (small[b] == '\0')
				return ((char*)big + i - b);
		}
		i = i - b;
		i++;
	}
	return (NULL);
}
