/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:08:27 by caunhach          #+#    #+#             */
/*   Updated: 2023/03/02 11:32:07 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	print_args(char c, void *arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_char((char)arg);
	else if (c == 's')
		i += print_str((char *)arg);
	else if (c == 'p')
		i += print_ptr((unsigned long long)arg);
	else if (c == 'd' || c == 'i')
		i += print_int((int)arg);
	else if (c == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (c == 'x')
		i += print_hex((unsigned int)arg, 'a');
	else if (c == 'X')
		i += print_hex((unsigned int)arg, 'A');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			if (ft_strchr("cspdiuxX", *(s + 1)))
				i += print_args(*(s + 1), va_arg(args, void *));
			else if (*(s + 1) == '%')
				i += print_char('%');
			s += 2;
		}
		else if (*s == '%' && !*(s + 1))
			break ;
		else
		{
			i += print_char(*s);
			s++;
		}
	}
	va_end(args);
	return (i);
}
