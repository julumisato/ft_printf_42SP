/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:30:01 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 15:30:35 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
