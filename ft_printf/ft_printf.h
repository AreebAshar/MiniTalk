/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:59:04 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/15 22:06:57 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	checker(char s, va_list args);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_uputnbr(unsigned int nb);
int	ft_hex_base(unsigned long nb, int flag);
#endif