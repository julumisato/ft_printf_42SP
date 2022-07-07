/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:49:12 by jusato            #+#    #+#             */
/*   Updated: 2022/07/06 21:22:09 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_printf *param, char c)
{
	int	i;

	i = 0;
	if (param->min > 0)
	{
		if (!param->left_posit)
		{
			while(i++ < param->min - 1)
				param->ret += write(1, " ", 1);
		}
		param->ret += write(1, &c, 1);
		if (param->left_posit)
		{
			while(i++ < param->min - 1)
				param->ret += write(1, " ", 1);
		}
	}
	else
		param->ret += write(1, &c, 1);
	return ;
}

void	ft_printf_num(t_printf *param, int value)
{
	if (value >= 0)
	{
		if (param->space)
			param->ret += write(1, " ", 1);
		else if (param->signal)
			param->ret += write(1, "+", 1);
	}
	ft_putnbr_fd(value, 1);
	param->ret += ft_numlen(value);
}
