/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:25:00 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/23 20:39:16 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*svgs;
	unsigned char		*svgd;
	size_t				i;

	svgs = src;
	svgd = dest;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		svgd[i] = svgs[i];
		if (svgs[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
