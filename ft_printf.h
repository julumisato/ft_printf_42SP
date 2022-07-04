/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:23:19 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 17:08:29 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_printf
{
	va_list		args;
	int			ret;
	int			fill_zero;
	int			left_posit;
	int			altern_form;
	int			space;
	int			signal;
}	t_printf;

/* initial functions (ft_printf.c) */
int			ft_printf(const char *format, ...);
int			ft_eval_format_string(const char *string, t_printf *params);
t_printf	*ft_init(t_printf	*init);
void		ft_flags(char flag, t_printf *params);

/* format functions (ft_printf_formats.c) */
void		ft_print_alnum(t_printf *params, char c, int i);
void		ft_print_str(t_printf *params, int i);
void		ft_printf_pointer(t_printf *params, int i);
void		ft_printf_unsigned_int(t_printf *p, int i);
void		ft_print_hexadecimal(char h, t_printf *params, int i);

/* utils (ft_printf_utils.c) */
int			ft_numlen(int num);
int			ft_sizehexa(unsigned long long n);
int			ft_unsigned_numlen(unsigned int n);
void		ft_put_unsignednbr(unsigned int n);
char		*ft_hexastr(unsigned long n, char h);
