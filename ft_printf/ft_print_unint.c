/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:14:25 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 19:58:12 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_rezult_unint(unsigned int a, int size, t_info *inf)
{
	int rez;

	rez = 0;
	if (size < inf->width && inf->flags == -1)
	{
		rez += print_count_char(inf->width - size, ' ');
		rez += ft_print_number(a, size);
	}
	else if (size < inf->width && inf->flags == 0 && inf->precision == -1)
	{
		rez += print_count_char(inf->width - size, '0');
		rez += ft_print_number(a, size);
	}
	else if (size < inf->width && inf->flags == 1)
	{
		rez += ft_print_number(a, size);
		rez += print_count_char(inf->width - size, ' ');
	}
	else if (size >= inf->width)
	{
		rez += ft_print_number(a, size);
	}
	return (rez);
}

int		ft_print_unint(unsigned int a, t_info *inf)
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
		size = inf->precision;
	return (print_rezult_unint(a, size, inf));
}
