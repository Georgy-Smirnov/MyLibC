/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:40 by kjaco             #+#    #+#             */
/*   Updated: 2021/04/03 14:37:44 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_dec_hex(unsigned int a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= 16;
		i++;
	}
	return (i);
}

void	print_dec_hex(unsigned int a)
{
	char	s[15];
	int		i;

	i = 0;
	if (a == 0)
		write(1, "0", 1);
	i = put_sizet_str(a, 'a', s);
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
}

int		ft_print_hexnum(unsigned int a, int size)
{
	if (size > count_dec_hex(a))
	{
		print_count_char(size - count_dec_hex(a), '0');
		print_dec_hex(a);
	}
	else
		print_dec_hex(a);
	return (size);
}

int		print_rezult_hex(unsigned int a, int size, t_info *inf)
{
	int rez;

	rez = 0;
	if (size < inf->width && inf->flags == -1)
	{
		rez += print_count_char(inf->width - size, ' ');
		rez += ft_print_hexnum(a, size);
	}
	else if (size < inf->width && inf->flags == 0 && inf->precision == -1)
	{
		rez += print_count_char(inf->width - size, '0');
		rez += ft_print_hexnum(a, size);
	}
	else if (size < inf->width && inf->flags == 1)
	{
		rez += ft_print_hexnum(a, size);
		rez += print_count_char(inf->width - size, ' ');
	}
	else if (size >= inf->width)
	{
		rez += ft_print_hexnum(a, size);
	}
	return (rez);
}

int		ft_print_hex(unsigned int a, t_info *inf)
{
	int count;
	int size;

	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
	if (inf->flags == 0 && inf->precision != -1)
		inf->flags = -1;
	if (a == 0 && inf->precision == 0)
		return (ft_print_exep(inf));
	count = count_dec_hex(a);
	if (inf->precision < count)
		size = count;
	else
		size = inf->precision;
	return (print_rezult_hex(a, size, inf));
}
