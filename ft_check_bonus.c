/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aram <aram@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:03:58 by mnazarya          #+#    #+#             */
/*   Updated: 2023/02/04 15:19:13 by aram             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_check_sharp(const char *str, va_list arg)
{
	int	count;

	count = 0;
	if (*str == 'x')
		count += ft_ptr((unsigned long long)va_arg(arg, unsigned int), 1);
	else if (*str == 'X')
		count += ft_ptr((unsigned long long)va_arg(arg, unsigned int), 0);
	return (count);
}

static int	ft_check_space(va_list arg)
{
	int	count;
	int	argument;

	count = 0;
	argument = va_arg(arg, int);
	if (argument >= 0)
	{
		count += write(1, " ", 1);
		count += ft_putnbr(argument);
	}
	else if (argument < 0)
		count += ft_putnbr(argument);
	return (count);
}

static int	ft_check_space_n(const char *str, va_list arg)
{
	int	count;
	int	s;

	count = 0;
	s = 0;
	if (*str >= 48 && *str <= 57)
	{
		s = ft_atoi(str);
		while (--s)
			count += write(1, " ", 1);
	}
	while (*str >= 48 && *str <= 57)
		str++;
	if (*str == 'i' || *str == 'd')
		count += ft_check_space(arg);
	else
	{
		str--;
		if (*str >= 48 && *str <= 57)
			count += write (1, " ", 1);
		count += ft_putstr(va_arg(arg, char *));
	}
	return (count);
}

static int	ft_check_plus(va_list arg)
{
	int	count;
	int	argument;

	count = 0;
	argument = va_arg(arg, int);
	if (argument >= 0)
	{
		count += write(1, "+", 1);
		count += ft_putnbr(argument);
	}
	else if (argument < 0)
		count += ft_putnbr(argument);
	return (count);
}

int	ft_check_flags(const char *str, va_list arg)
{
	int	count;

	count = 0;
	if (*str == '#')
	{
		str++;
		count += ft_check_sharp(str, arg);
	}
	else if (*str == '+')
	{
		str++;
		count += ft_check_plus(arg);
	}
	else if (*str == ' ')
	{
		str++;
		count += ft_check_space_n(str, arg);
	}
	return (count);
}
