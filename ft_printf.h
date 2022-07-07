/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:23:19 by jusato            #+#    #+#             */
/*   Updated: 2022/07/06 21:46:06 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_printf
{
	va_list		args;
	int			ret;
	int			fill_zero;
	int			left_posit;
	int			altern_form;
	int			space;
	int			signal;
	int			min;
}	t_printf;

/* initial functions (ft_printf.c) */
int			ft_printf(const char *format, ...);
int			ft_eval_format_string(t_printf *param, const char *string);
t_printf	*ft_init(t_printf	*init);
int			ft_flags(t_printf *param, char *flag);

/* format functions (ft_printf_formats.c) */
void		ft_printf_alnum(t_printf *param, char c);
void		ft_printf_string(t_printf *param);
void		ft_printf_pointer(t_printf *param);
void		ft_printf_unsigned_int(t_printf *param);
void		ft_printf_hexadecimal(t_printf *param, char h);

/* utils (ft_printf_utils[1/2].c) */
int			ft_numlen(int num);
int			ft_sizehexa(unsigned long long n);
int			ft_unsigned_numlen(unsigned int n);
void		ft_put_unsignednbr(unsigned int n);
char		*ft_hexastr(unsigned long n, char h);
void		ft_printf_char(t_printf *param, char c);
void		ft_printf_num(t_printf *param, int value);

#endif
