/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:14:39 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/10/08 23:05:27 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int	ft_printf(const char *pri, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnum(int num);
int	ft_putunnum(unsigned int num);
int	ft_puthhh(unsigned int n);
int	ft_puthex(unsigned int n);
int	ft_point(void *a);

#endif