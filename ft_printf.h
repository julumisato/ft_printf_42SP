/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:23:19 by jusato            #+#    #+#             */
/*   Updated: 2022/06/18 02:07:25 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_printf
{
	va_list		args;
	int			ret;	//lenght to return
	int			fill_zero;
	int			left_posit;
	int			altern_form;
	int			space;
	int			signal;
}		t_printf;

int	ft_printf(const char *format, ...);

t_printf	*ft_init(t_printf	*init);
void	ft_flags(char flag, t_printf *params);

//testes
void	ft_print_hexadecimal(char h, t_printf *params);