/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:27:04 by jusato            #+#    #+#             */
/*   Updated: 2022/06/18 00:22:00 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //teste
#include <ctype.h> //teste

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

t_printf	*ft_eval_format_string(const char *string, t_printf *params)
{
	int	i;

	i = 1;
	while (!ft_strchr("cspdiuxX%", string[i]))
	{
		ft_flags(string[i + 1], params);
		i ++;
	}
	if (string[i] == 'c')
	{
		int	c = va_arg(params->args, int);
		ft_putchar_fd(c, 1);
		params->ret -= i;
	}
	else if (string[i] == 's')
	{
		char	*str = va_arg(params->args, char *);
		ft_putstr_fd(str, 1);
		params->ret += ft_strlen(str) - (i + 1);
	}
	//else if (string[i] == 'p')
	else if (string[i] == 'd' || string[i] == 'i')
	{
		int	x = va_arg(params->args, int);
		ft_putnbr_fd(x, 1);
		params->ret += ft_numlen(x) - (i + 1);
	}
	//else if (string[i] == 'u')
	else if (string[i] == 'x' || string[i] == 'X')
		ft_print_hexadecimal(string[i], params);
	else if (string[i] == '%')
		write(1, "%", 1);
	return (params);
}

int	ft_printf(const char *string, ...)
{
	int			i;
	t_printf	*params;
	int			retvalue;

	params = (t_printf *)malloc(sizeof(t_printf));
	if (!params)
		return (-1);
	ft_init(params);
	va_start(params->args, string);
	retvalue = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			ft_eval_format_string(&string[i], params);
			i ++;
		}
		else
			write(1, &string[i], 1);
		i ++;
	}
	retvalue = i + params->ret;
	va_end(params->args);
	free(params);
	return (retvalue);
}

int	main(void)
{
	int orig = printf("hello %d.\n", 1234);
	printf("ret orig: %d\n", orig);
	int new = ft_printf("hello %d.\n", 1234);
	printf("ret impl: %d\n", new);
	return (0);
}

/*Compile*/
// gcc ft_printf.c ft_printf_utils.c libftprintf.a && ./a.out