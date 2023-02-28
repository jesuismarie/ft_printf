/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:09:23 by mnazarya          #+#    #+#             */
/*   Updated: 2023/02/07 11:50:01 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_pers(const char *str, va_list arg)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_check_flags(str, arg);
			if (*str == ' ' || *str == 'd' || *str == 'i' 
				|| (*str >= 48 && *str <= 57))
				while (*str == ' ' || *str == 'd' || *str == 'i' 
					|| (*str >= 48 && *str <= 57))
					++str;
			else
				str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	if (!ft_parse_bonus(str))
		return (0);
	va_start(arg, str);
	count += is_pers(str, arg);
	va_end(arg);
	return (count);
}
