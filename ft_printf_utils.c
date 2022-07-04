/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:31:50 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 16:10:13 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_sizehexa(unsigned long long n)
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

int	ft_unsigned_numlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

void	ft_put_unsignednbr(unsigned int n)
{
	if (n >= 10)
		ft_put_unsignednbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return ;
}

char	*ft_hexastr(unsigned long n, char h)
{
	int		size;
	char	*hexabase;
	char	*hexa;

	if (h == 'x')
		hexabase = "0123456789abcdef";
	if (h == 'X')
		hexabase = "0123456789ABCDEF";
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
