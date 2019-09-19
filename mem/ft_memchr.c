/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:32:41 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/14 16:30:30 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*svg;
	size_t				i;

	svg = str;
	i = 0;
	while (i < n)
		if (svg[i] != (unsigned char)c)
			i++;
		else
			return ((void *)str + i);
	return (NULL);
}
