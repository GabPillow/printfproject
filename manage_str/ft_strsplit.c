/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 20:55:04 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/27 14:35:24 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnuml(char const *s, char c)
{
	int	l;
	int i;

	i = 0;
	l = 0;
	while (s[i] != c && s[i])
	{
		i++;
		l++;
	}
	return (l);
}

static char	*ft_freestr(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_getnumw(s, c) + 1))))
		return (NULL);
	if (tab == '\0')
		return (0);
	while (i < ft_getnumw(s, c))
	{
		while (s[b] == c)
			b++;
		if (!(tab[i] = ft_strsub(s, b, getnuml(&s[b], c))))
		{
			ft_freestr(tab, ft_getnumw(s, c) + 1);
			return (NULL);
		}
		i++;
		while (s[b] != c && s[b])
			b++;
	}
	tab[i] = 0;
	return (tab);
}
