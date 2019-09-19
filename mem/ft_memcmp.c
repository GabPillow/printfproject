/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:41:55 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/14 17:38:24 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*svg1;
	const unsigned char	*svg2;

	svg1 = s1;
	svg2 = s2;
	while (n--)
		if (*svg1 != *svg2)
			return (*svg1 - *svg2);
		else
		{
			svg1++;
			svg2++;
		}
	return (0);
}
