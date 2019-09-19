/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:31:03 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/22 18:08:48 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest += (n - 1);
		src += (n - 1);
		while (n--)
			(*(char*)dest--) = (*(const char*)src--);
		return (dest + 1);
	}
	return (dest);
}
