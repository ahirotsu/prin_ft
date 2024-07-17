/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:55:09 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/10/08 23:06:26 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countdigi(int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count ++;
	}
	return (count);
}

int	ft_putnum(int num)
{
	int	i;

	if (num != INT_MIN)
		i = countdigi(num);
	if (num == INT_MIN)
		return (ft_putstr("-2147483648"));
	else if (num < 0)
	{
		ft_putchar('-');
		ft_putnum(-num);
	}
	else if (num >= 10)
	{
		ft_putnum(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num % 10 + '0');
	return (i);
}
