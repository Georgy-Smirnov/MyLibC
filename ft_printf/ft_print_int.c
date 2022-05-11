/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:38:50 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 20:47:27 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_digit_in_number(long long int a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		i++;
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int		ft_print_number(long long int a, int size)
{
	if (size > count_digit_in_number(a))
	{
		if (a < 0)
		{
			write(1, "-", 1);
			print_count_char(size - count_digit_in_number(a), '0');
			ft_putnbr_fd(-a, 1);
		}
		else
		{
			print_count_char(size - count_digit_in_number(a), '0');
			ft_putnbr_fd(a, 1);
		}
	}
	else
		ft_putnbr_fd(a, 1);
	return (size);
}

int		check_integer(int a, int size, t_info *inf)
{
	int rez;

	rez = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		rez++;
		rez += print_count_char(inf->width - size - 1, '0');
		rez += ft_print_number(-a, size);
	}
	else
	{
		rez += print_count_char(inf->width - size, '0');
		rez += ft_print_number(a, size);
	}
	return (rez);
}

int		print_rezult_int(int a, int size, t_info *inf)
{
	int rez;

	rez = 0;
	if (size < inf->width && inf->flags == -1)
	{
		rez += print_count_char(inf->width - size, ' ');
		rez += ft_print_number(a, size);
	}
	else if (size < inf->width && inf->flags == 0 && inf->precision == -1)
		rez += check_integer(a, size, inf);
	else if (size < inf->width && inf->flags == 1)
	{
		rez += ft_print_number(a, size);
		rez += print_count_char(inf->width - size, ' ');
	}
	else if (size >= inf->width)
		rez += ft_print_number(a, size);
	return (rez);
}

int		ft_print_int(int a, t_info *inf)
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
	count = count_digit_in_number(a);
	if (inf->precision < count)
		size = count;
	else
	{
		if (a < 0)
			size = inf->precision + 1;
		else
			size = inf->precision;
	}
	return (print_rezult_int(a, size, inf));
}
