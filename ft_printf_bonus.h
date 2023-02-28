/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:44:03 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/29 20:44:03 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_parse_bonus(const char *str);
int		ft_atoi(const char *str);
int		is_pers(const char *str, va_list arg);
int		ft_check_flags(const char *str, va_list arg);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_hex(unsigned long long n, short x);
int		ft_ptr(unsigned long long n, short x);

#endif
