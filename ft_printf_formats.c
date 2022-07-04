/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:52:29 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 16:30:36 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!str)
	{
		write(1, "(null)", 6);
		params->ret += (6 - (i + 1));
		return ;
	}
	ft_putstr_fd(str, 1);
	params->ret += ft_strlen(str) - (i + 1);
	return ;
}

void	ft_printf_pointer(t_printf *params, int i)
{
	unsigned long	pointer;
	char			*str;

	pointer = (unsigned long)va_arg(params->args, void *);
	if (pointer == 0)
	{
		params->ret += write(1, "(nil)", 5) - (i + 1);
		return ;
	}
	str = ft_hexastr(pointer, 'x');
	if (!str)
	{
		params->ret += write(1, "(null)", 6);
		return ;
	}
	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	params->ret += ft_strlen(str);
	free(str);
	return ;
}

void	ft_printf_unsigned_int(t_printf *p, int i)
{
	long	ui;

	ui = va_arg(p->args, unsigned int);
	if (ui < 0)
		ui = (4294967295 + ui);
	ft_put_unsignednbr(ui);
	p->ret += ft_unsigned_numlen(ui) - (i + 1);
	return ;
}

void	ft_print_hexadecimal(char h, t_printf *params, int i)
{
	unsigned int	hexa;
	char			*str;

	hexa = va_arg(params->args, unsigned int);
	str = ft_hexastr(hexa, h);
	if (!str)
	{
		write(1, "(null)", 6);
		params->ret += 6;
		return ;
	}
	if (params->altern_form)
	{
		if (h == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
	ft_putstr_fd(str, 1);
	if (params->altern_form)
		params->ret += ft_strlen(str) - (i - 1);
	else
		params->ret += ft_strlen(str) - (i + 1);
	free(str);
	return ;
}
