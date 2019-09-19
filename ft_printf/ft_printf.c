/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:27:02 by grochefo          #+#    #+#             */
/*   Updated: 2019/04/02 04:44:14 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*putseg(char *print, const char *format, int b)
{
	char	*buff;

	ft_exit(((buff = ft_strndup(format, b)) != NULL));
	ft_exit(((print = ft_strjoinplus(print, buff, 3)) != NULL));
	return (print);
}

static char			*createprint(va_list ap, const char *format, char *print)
{
	t_format	*form;
	int			i;
	int			b;

	ft_exit(((form = malloc(sizeof(t_format))) != NULL));
	i = 0;
	b = 1;
	while (format[i])
	{
		if (format[i] == '%' || format[i] == '{')
		{
			print = putseg(print, format + (i - (b - 1)), b - 1);
			i += find_format(format + i, form, ap);
			print = verifyform(form, print);
			ft_exit(((print = ft_strjoinplus(print, create_seg(form, ap), 3))
			!= NULL));
			b = 0;
		}
		format[i] ? b++ : 0;
		format[i] ? i++ : 0;
	}
	if (b > 0)
		print = putseg(print, format + (i - (b - 1)), b - 1);
	free(form);
	return (print);
}

int					ft_printf(const char *format, ...)
{
	char	*print;
	va_list ap;
	size_t	ret;
	int		i;

	ret = 0;
	i = 0;
	print = NULL;
	va_start(ap, format);
	print = createprint(ap, format, print);
	va_end(ap);
	while (print[i])
	{
		if (!(ft_strncmp(print + i, NULLC, 7)))
		{
			ft_putchar('\0');
			i += 6;
		}
		else
			ft_putchar(print[i]);
		ret++;
		i++;
	}
	ft_strdel(&print);
	return (ret);
}
