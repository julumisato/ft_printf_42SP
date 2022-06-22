/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:52:29 by jusato            #+#    #+#             */
/*   Updated: 2022/06/21 19:14:56 by jusato           ###   ########.fr       */
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
	if (num < 0)
		len ++;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

static int	ft_sizehexa(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i ++;
	}
	return (i);
}

static char	*ft_hexastr(unsigned long n, char *hexabase)
{
	int		size;
	char	*hexa;

	size = ft_sizehexa(n);
	hexa = malloc(sizeof(char) * (size + 1));
	if (!hexa)
		return (NULL);
	hexa[size] = '\0';
	size --;
	while (size >= 0)
	{
		hexa[size] = hexabase[n % 16];
		n = n / 16;
		size --;
	}
	return (hexa);
}

void	ft_print_hexadecimal(char h, t_printf *params, int i)
{
	unsigned int	hexa;
	char			*str;

	hexa = va_arg(params->args, unsigned int);
	if (h == 'x')
		str = ft_hexastr(hexa, "0123456789abcdef");
	else if (h == 'X')
		str = ft_hexastr(hexa, "0123456789ABCDEF");
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

void	ft_printf_pointer(t_printf *params)
{
	unsigned long	pointer;
	char				*str;

	pointer = (unsigned long)va_arg(params->args, void *);
	str = ft_hexastr(pointer, "0123456789abcdef");
	if (!str)
	{
		params->ret += write(1, "(null)", 6);
		return ;
	}
	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	params->ret += ft_strlen(str);
	printf("\nstr:%s, strlen=%ld\n", str, ft_strlen(str));
	free(str);
	return ;
}

void	ft_printf_unsigned_int(t_printf *p, int i)
{
	unsigned int	ui;

	ui = (unsigned int)va_arg(p->args, unsigned int);
	ui = (unsigned int)(4294967295 + 1 + ui);
	ft_putnbr_fd(ui, 1);
	p->ret += ft_numlen(ui) - (i + 1);
	return ;
}
