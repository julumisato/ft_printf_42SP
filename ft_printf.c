/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:27:04 by jusato            #+#    #+#             */
/*   Updated: 2022/07/06 20:08:36 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_init(t_printf	*init)
{
	init->ret = 0;
	init->left_posit = 0;
	init->fill_zero = 0;
	init->altern_form = 0;
	init->space = 0;
	init->signal = 0;
	return (init);
}
int	ft_width_eval(t_printf *param, char *flag);

int	ft_flags(t_printf *param, char *flag)
{
	int	i;

	i = 0;
	while(ft_strchr("0-# +", flag[i]))
	{
		if (flag[i] == '0')
			param->fill_zero = 1;
		else if (flag[i] == '-')
			param->left_posit = 1;
		else if (flag[i] == '#')
			param->altern_form = 1;
		else if (flag[i] == ' ')
			param->space = 1;
		else if (flag[i] == '+')
			param->signal = 1;
		i ++;
	}
	while(!ft_strchr("cspdiuxX%", flag[i]))
		i ++;
	return (i);
}

void	ft_reset_flags(t_printf *param)
{
	param->left_posit = 0;
	param->fill_zero = 0;
	param->altern_form = 0;
	param->space = 0;
	param->signal = 0;
	return ;
}

int	ft_eval_format_string(t_printf *param, const char *string)
{
	int	i;

	i = 1;
	if (!ft_strchr("cspdiuxX%", string[i]))
		i += ft_flags(param, (char *)&string[i]);
	if (string[i] == 'c' || string[i] == 'd' || string[i] == 'i'
		|| string[i] == '%')
		ft_printf_alnum(param, string[i]);
	else if (string[i] == 's')
		ft_printf_string(param);
	else if (string[i] == 'p')
		ft_printf_pointer(param);
	else if (string[i] == 'u')
		ft_printf_unsigned_int(param);
	else if (string[i] == 'x' || string[i] == 'X')
		ft_printf_hexadecimal(param, string[i]);
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int			i;
	t_printf	*param;
	int			retvalue;

	param = (t_printf *)malloc(sizeof(t_printf));
	if (!param)
		return (-1);
	ft_init(param);
	va_start(param->args, string);
	retvalue = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
			i += ft_eval_format_string(param, &string[i]);
		else
			param->ret += write(1, &string[i], 1);
		i ++;
	}
	retvalue = param->ret;
	va_end(param->args);
	free(param);
	return (retvalue);
}
