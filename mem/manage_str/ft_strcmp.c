/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:35:13 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/16 17:30:07 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;
	int b;

	b = 0;
	a = 0;
	while ((unsigned char)s1[a] && s1[a] == s2[b])
	{
		a++;
		b++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[b]);
}
