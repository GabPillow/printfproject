/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_seg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:21:30 by grochefo          #+#    #+#             */
/*   Updated: 2019/04/02 03:59:01 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*formcolor(t_format *form, char *buff)
{
	form->color == 'B' ? ft_exit(((buff = ft_strdup(BLACK)) != NULL)) : 0;
	form->color == 'R' ? ft_exit(((buff = ft_strdup(RED)) != NULL)) : 0;
	form->color == 'G' ? ft_exit(((buff = ft_strdup(GREEN)) != NULL)) : 0;
	form->color == 'Y' ? ft_exit(((buff = ft_strdup(YELLOW)) != NULL)) : 0;
	form->color == 'b' ? ft_exit(((buff = ft_strdup(BLUE)) != NULL)) : 0;
	form->color == 'P' ? ft_exit(((buff = ft_strdup(PINK)) != NULL)) : 0;
	form->color == 'C' ? ft_exit(((buff = ft_strdup(CYAN)) != NULL)) : 0;
	form->color == 'g' ? ft_exit(((buff = ft_strdup(GREY)) != NULL)) : 0;
	form->color == 'E' ? ft_exit(((buff = ft_strdup(EOC)) != NULL)) : 0;
	return (buff);
}

static char		*formseg(t_format *form, va_list ap, char *buff)
{
	form->type == 's' ? buff = ft_print_s(buff, ap, form) : 0;
	form->type == 'c' || form->type == 'C'
	? buff = ft_print_c(buff, (char)va_arg(ap, int), form) : 0;
	form->type == 'd' || form->type == 'i' || form->type == 'D' ?
	buff = ft_print_d(buff, ap, form) : 0;
	form->type == 'o' || form->type == 'O' ? buff = ft_print_o(buff, ap, form) :
	0;
	form->type == 'x' ? buff = ft_print_x(buff, ap, form) : 0;
	form->type == 'X' ? buff = ft_print_xmaj(buff, ap, form) : 0;
	form->type == 'u' || form->type == 'U' ? buff = ft_print_u(buff, ap, form) :
	0;
	form->type == 'b' ? buff = ft_print_b(buff, ap, form) : 0;
	form->type == 'f' || form->type == 'F' ?
	buff = ft_print_f(buff, ap, form) : 0;
	form->type == 'p' ? buff = ft_print_p(buff, ap, form) : 0;
	form->type == '%' ? buff = ft_print_c(buff, '%', form) : 0;
	return (buff);
}

char			*create_seg(t_format *form, va_list ap)
{
	char	*buff;

	buff = NULL;
	if (!form->color && form->type)
		buff = formseg(form, ap, buff);
	else if (!form->type && form->color)
		buff = formcolor(form, buff);
	return (buff);
}
