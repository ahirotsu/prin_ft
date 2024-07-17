/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:03:38 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/10/08 22:49:07 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	changeper(char a, va_list args)
{
	if (a == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (a == 'p')
		return (ft_point(va_arg(args, void *)));
	else if (a == 'd')
		return (ft_putnum(va_arg(args, int)));
	else if (a == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (a == 'u')
		return (ft_putunnum(va_arg(args, unsigned int)));
	else if (a == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	else if (a == 'X')
		return (ft_puthhh(va_arg(args, unsigned int)));
	else if (a == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

static int	checkper(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *pri, ...)
{
	va_list	args;
	int		count;
	int		k;
	int		i;

	va_start(args, pri);
	k = 0;
	count = 0;
	i = 0;
	while (pri[i] != '\0')
	{
		if (pri[i] == '%')
		{
			i++;
			if (!checkper(pri[i]))
				return (count);
			count += changeper(pri[i], args);
		}
		else
			count += ft_putchar(pri[i]);
		i++;
	}
	va_end(args);
	return (count);
}
