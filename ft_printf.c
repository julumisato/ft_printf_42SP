/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:27:04 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 16:38:02 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format_string(const char *string, t_printf *params)
{
	int	i;

	i = 1;
	while (!ft_strchr("cspdiuxX%", string[i]) && string[i])
		ft_flags(string[i ++], params);
	if (string[i] == 'c' || string[i] == 'd' || string[i] == 'i'
		|| string[i] == '%')
		ft_print_alnum(params, string[i], i);
	else if (string[i] == 's')
		ft_print_str(params, i);
	else if (string[i] == 'p')
		ft_printf_pointer(params, i);
	else if (string[i] == 'u')
		ft_printf_unsigned_int(params, i);
	else if (string[i] == 'x' || string[i] == 'X')
		ft_print_hexadecimal(string[i], params, i);
	return (i);
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
			i += ft_eval_format_string(&string[i], params);
		else
			write(1, &string[i], 1);
		i ++;
	}
	retvalue = i + params->ret;
	va_end(params->args);
	free(params);
	return (retvalue);
}
