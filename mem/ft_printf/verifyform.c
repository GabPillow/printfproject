/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifyform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:01 by grochefo          #+#    #+#             */
/*   Updated: 2019/04/02 03:51:34 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*verifyform(t_format *form, char *print)
{
	form->color == '{' ?
	ft_exit(((print = ft_strjoinplus(print, "{", 1)) != NULL)) : 0;
	if (form->type != 'd' && form->type != 's' && form->type != 'p' \
	&& form->type != 'i' && form->type != 'c' && form->type != 'X' && \
	form->type != 'x' && form->type != 'u' && form->type != 'o' && \
	form->type != 'b' && form->type != 'f' && form->type != '%' && \
	form->type != 'D' && form->type != 'C' && form->type != 'F' && \
	form->type != 'O' && form->type != 'U')
		ft_exit(((print = ft_strjoinplus(print, &form->type, 1)) != NULL));
	(form->type == 'D' || form->type == 'O'
	|| form->type == 'U') && !(form->flag & L) ? form->flag += L : 0;
	return (print);
}
