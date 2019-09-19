/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:43:14 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/27 14:33:00 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (!(s) || !(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(new_str, &s[start], len);
	new_str[len] = '\0';
	return (new_str);
}
