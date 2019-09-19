/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:27:33 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/21 17:18:11 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_manage_precexep(char *buff, t_format *form)
{
	ft_strdel(&buff);
	if ((form->type == 'd' || form->type == 'i') && form->flag & PLUS)
		ft_exit(((buff = ft_strdup("+")) != NULL));
	else if (form->large > 0)
		ft_exit(((buff = ft_strnew(form->large)) != NULL));
	if (form->large > 0)
		buff = ft_manage_space(buff, form);
	return (buff);
}

static void		ft_placesigns(char *buff, char *space, t_format *form, char s)
{
	s == '0' && (buff[0] == '-' || buff[0] == '+' || buff[0] == ' ')
	? space[0] = buff[0] : 0;
	s == '0' && (buff[0] == '-' || buff[0] == '+' || buff[0] == ' ')
	? buff[0] = '0' : 0;
	form->flag & HASH && s == '0' && (form->type == 'x' || form->type == 'X')
	? buff[1] = '0' : 0;
}

char			*ft_manage_space(char *buff, t_format *form)
{
	char	*space;
	char	s;
	int		t;

	s = ' ';
	!(form->flag & LESS) && form->flag & ZERO && form->prec == -1 ? s = '0' : 0;
	!(form->flag & LESS) &&
	form->type == 'f' && form->flag & ZERO ? s = '0' : 0;
	t = form->large - ft_strlen(buff);
	!(ft_strncmp(buff, NULLC, 7)) ? t = form->large - 1 : 0;
	ft_exit(((space = ft_strnew(t)) != NULL));
	ft_bzero(space, t);
	while (t--)
		space[t] = s;
	ft_placesigns(buff, space, form, s);
	form->flag & LESS ?
	ft_exit(((buff = ft_strjoinplus(buff, space, 3)) != NULL)) : 0;
	!(form->flag & LESS) ?
	ft_exit(((buff = ft_strjoinplus(space, buff, 3)) != NULL)) : 0;
	form->flag & HASH && s == '0' && (form->type == 'x' || form->type == 'X')
	? buff[1] = form->type : 0;
	return (buff);
}

char			*ft_manage_prec(char *buff, t_format *form)
{
	char	*str_new;
	size_t	t;
	int		s;

	s = 0;
	form->type == 's' ?
	ft_exit(((str_new = ft_strndup(buff, form->prec)) != NULL)) : 0;
	if (form->type != 's')
	{
		buff && (buff[0] == '-' || buff[0] == '+') ? s = 1 : 0;
		if (buff)
			t = form->prec - ft_strlen(buff) + s;
		else
			t = form->prec;
		ft_exit(((str_new = ft_strnew(t + s)) != NULL));
		ft_bzero(str_new, t);
		while (t--)
			str_new[t] = '0';
		s == 1 ? str_new[0] = buff[0] : 0;
		s == 1 ? buff[0] = '0' : 0;
		ft_exit(((str_new = ft_strjoinplus(str_new, buff, 3)) != NULL));
	}
	else
		((int)ft_strlen(buff) > form->prec) ? ft_strdel(&buff) : 0;
	return (str_new);
}
