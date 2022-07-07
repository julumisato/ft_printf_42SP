/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:52:29 by jusato            #+#    #+#             */
/*   Updated: 2022/07/07 15:48:22 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_alnum(t_printf *param, char c)
{
	int	value;

	if (c == '%')
	{
		param->ret += write(1, &c, 1);
		return ;
	}
	value = va_arg(param->args, int);
	if (c == 'c')
		ft_printf_char(param, value);
	else if (c == 'd' || c == 'i')
		ft_printf_num(param, value);
	return ;
}

void	ft_printf_string(t_printf *param)
{
	char	*str;

	str = va_arg(param->args, char *);
	if (!str)
		ft_printf_str_width(param, "(null)");
	else
		ft_printf_str_width(param, str);
	return ;
}

void	ft_printf_pointer(t_printf *param)
{
	unsigned long	pointer;
	char			*str;

	pointer = (unsigned long)va_arg(param->args, void *);
	if (pointer == 0)
	{
		ft_printf_str_width(param, "(nil)");
		return ;
	}
	str = ft_hexastr(pointer, 'x');
	if (!str)
		ft_printf_str_width(param, "(null)");
	else
	{
		ft_printf_ptr_width(param, str);
		free(str);
	}
	return ;
}

void	ft_printf_unsigned_int(t_printf *param)
{
	long	ui;

	ui = va_arg(param->args, unsigned int);
	ft_put_unsignednbr(ui);
	param->ret += ft_unsigned_numlen(ui);
	return ;
}

void	ft_printf_hexadecimal(t_printf *param, char h)
{
	unsigned int	hexa;
	char			*str;

	hexa = va_arg(param->args, unsigned int);
	if (hexa == 0)
	{
		ft_printf_str_width(param, "0");
		return ;
	}
	str = ft_hexastr(hexa, h);
	if (!str)
	{
		ft_printf_str_width(param, "(null)");
		return ;
	}
	if (param->altern_form)
	{
		param->ret += write(1, "0", 1);
		param->ret += write(1, &h, 1);
	}
	ft_printf_str_width(param, str);
	free(str);
	return ;
}
