/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:27:04 by jusato            #+#    #+#             */
/*   Updated: 2022/06/17 21:43:37 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //teste
#include <ctype.h> //teste

t_printf	*ft_eval_format_string(const char *string, t_printf *params)
{
	int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", string[i + 1]))
	{
		ft_flags(string[i + 1], params);
		i ++;
	}
	if (string[i + 1] == 'c')
		ft_putchar_fd(va_arg(params->args, int), 1);
	else if (string[i + 1] == 's')
		ft_putstr_fd(va_arg(params->args, char *), 1);
	//else if (string[i + 1] == 'p')
	else if (string[i + 1] == 'd')
		ft_putnbr_fd(va_arg(params->args, int), 1);
	//else if (string[i + 1] == 'i')
	//else if (string[i + 1] == 'u')
	else if (string[i + 1] == 'x' || string[i + 1] == 'X')
		ft_print_hexadecimal(string[i + 1], params);
	else if (string[i+1] == '%')
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
	//int orig =
	printf("hello %#x.\n", 42);
	//printf("ret orig: %d\n", orig);
	//int new = 
	ft_printf("hello %#x.\n", 42);
	//printf("ret impl: %d\n", new);
	return (0);
}

/*Compile*/
// gcc ft_printf.c ft_printf_utils.c libftprintf.a && ./a.out