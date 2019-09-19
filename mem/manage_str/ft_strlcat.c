/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:33:07 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/21 20:03:40 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size_dest)
{
	size_t	end_dest;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	end_dest = size_dest - ft_strlen(dest) - 1;
	if (len_dest >= size_dest)
		return (size_dest + ft_strlen(src));
	ft_strncat(dest, src, end_dest);
	return (len_dest + ft_strlen(src));
}
