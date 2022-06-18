/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:52:29 by jusato            #+#    #+#             */
/*   Updated: 2022/06/18 02:33:43 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //teste 

t_printf	*ft_init(t_printf	*init)
{
	init->ret = 0;
	init->fill_zero = 0;
	init->left_posit = 0;
	init->altern_form = 0;
	init->space = 0;
	init->signal = 0;
	return (init);
}

void	ft_flags(char flag, t_printf *params)
{
	if (flag == '0')
		params->fill_zero = 1;
	if (flag == '-')
		params->left_posit = 1;
	if (flag == '#')
		params->altern_form = 1;
	if (flag == ' ')
		params->space = 1;
	if (flag == '+')
		params->signal = 1;
	return ;
}

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

//not functional
void	ft_print_hexadecimal(char h, t_printf *params)
{
	unsigned int	hexa;

	hexa = va_arg(params->args, unsigned int);
	if (h == 'x')
	{
		if (params->altern_form)
			ft_putstr_fd("0x", 1);
	}
	else if (h == 'X')
	{
		if (params->altern_form)
			ft_putstr_fd("0X", 1);
	}
	return ;
}

void	ft_print_alnum(t_printf *params, char c, int i)
{
	int	value;

	if (c == '%')
	{
		write(1, "%", 1);
		params->ret -= i;
		return ;
	}
	value = va_arg(params->args, int);
	if (c == 'c')
	{
		ft_putchar_fd(value, 1);
		params->ret -= i;
	}
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(value, 1);
		params->ret += ft_numlen(value) - (i + 1);
	}
	return ;
}

void	ft_print_str(t_printf *params, int i)
{
	char	*str;

	str = va_arg(params->args, char *);
	ft_putstr_fd(str, 1);
	params->ret += ft_strlen(str) - (i + 1);
	return ;
}
