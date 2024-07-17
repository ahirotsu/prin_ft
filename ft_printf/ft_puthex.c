/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:59:06 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/10/08 22:08:17 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_len(unsigned int n)
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

static void	changehex(unsigned int n)
{
	if (n >= 16)
	{
		changehex(n / 16);
		changehex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'a' - 10);
	}
}

int	ft_puthex(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	changehex(n);
	return (n_len(n));
}

static void	changehhh(unsigned int n)
{
	if (n >= 16)
	{
		changehhh(n / 16);
		changehhh(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'A' - 10);
	}
}

int	ft_puthhh(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	changehhh(n);
	return (n_len(n));
}
