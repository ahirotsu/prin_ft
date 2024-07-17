/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:16:14 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/12/22 15:42:57 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	countundigi(unsigned int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num != 0)
	{
		num = num / 10;
		count ++;
	}
	return (count);
}

int	ft_putunnum(unsigned int num)
{
	int	i;

	i = countundigi(num);
	if (num >= 10)
	{
		ft_putunnum(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num % 10 + '0');
	return (i);
}
