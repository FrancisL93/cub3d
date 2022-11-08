/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:30:54 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:02:18 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

static int	print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	print_nbr(unsigned long num, int base, char conv)
{
	char	*print;
	char	*ptr;
	char	buffer[50];
	int		ret;

	print = "0123456789abcdef";
	ret = 0;
	if (conv == 'X')
		print = "0123456789ABCDEF";
	else if (conv == 'p')
		ret += write(1, "0x", 2);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = print[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = print[num % base];
		num /= base;
	}
	while (*ptr)
		ret += write(1, &*ptr++, 1);
	return (ret);
}

static int	convert(char c, va_list args, int i)
{
	if (c == 'x' || c == 'X')
		return (print_nbr(va_arg(args, unsigned int), 16, c));
	if (c == 'p')
		return (print_nbr(va_arg(args, unsigned long), 16, c));
	if (c == 'd' || c == 'i' || c == 'u')
	{
		i = va_arg(args, int);
		if (i < 0 && c == 'u')
			return (print_nbr(4294967296 + i, 10, c));
		if (i < 0)
		{
			if (i == -2147483648)
				return (write(1, "-2147483648", 11));
			return (write (1, "-", 1) + print_nbr(-i, 10, c));
		}
		return (print_nbr(i, 10, c));
	}
	if (c == '%')
		return (print_char('%'));
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX%", *str))
				ret += convert(*str++, args, i);
			else
				return (0);
		}
		else
		{
			write (1, &*str++, 1);
			ret += 1;
		}
	}
	va_end(args);
	return (ret);
}
