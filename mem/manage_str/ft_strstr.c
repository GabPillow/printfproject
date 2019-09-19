/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:19:42 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/22 15:27:59 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	int i;
	int b;

	i = 0;
	if (small[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		b = 0;
		while (big[i] == small[b])
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
