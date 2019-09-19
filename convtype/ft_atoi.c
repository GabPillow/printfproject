/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:37:59 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/13 17:16:43 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	int		n;

	n = 1;
	a = 0;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 15) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+' || (str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] == '-')
			n = -1;
		else if (str[i] >= 48 && str[i] <= 57)
			a = str[i] - '0';
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		a = (str[i] - '0') + a * 10;
		i++;
	}
	return (a * n);
}
