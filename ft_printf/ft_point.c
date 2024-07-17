/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:52:18 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/10/08 23:00:00 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	changehe(uintptr_t n)
{
	if (n >= 16)
	{
		changehe(n / 16);
		changehe(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'a' - 10);
	}
}

int	pointlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_point(void *a)
{
	int		s;

	if ((uintptr_t)a == 0)
		return (write(1, "0x0", 3));
	s = write (1, "0x", 2);
	changehe((uintptr_t)a);
	s += pointlen((uintptr_t)a);
	return (s);
}
