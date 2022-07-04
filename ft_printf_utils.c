/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:31:50 by jusato            #+#    #+#             */
/*   Updated: 2022/07/04 15:39:34 by jusato           ###   ########.fr       */
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

char	*ft_hexastr(unsigned long n, char *hexabase)
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
