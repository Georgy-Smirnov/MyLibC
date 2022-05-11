/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:42:05 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/18 21:59:18 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		put_sizet_str(size_t a, char c, char *s)
{
	int i;

	i = 0;
	while (a)
	{
		if (a % 16 <= 9)
			s[i] = a % 16 + '0';
		else
			s[i] = (a % 16) % 10 + c;
		a /= 16;
		i++;
	}
	return (i - 1);
}

int		count_pointer(size_t a)
{
	int i;

	i = 0;
	if (a == 0)
		return (3);
	while (a)
	{
		a /= 16;
		i++;
	}
	return (i + 2);
}

int		print_pointer(size_t a, t_info *inf)
{
	char	s[15];
	int		i;
	int		rez;

	i = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	rez = 2;
	if (a == 0 && inf->precision != 0)
	{
		write(1, "0", 1);
		rez++;
	}
	if (inf->precision == 0)
		return (rez);
	i = put_sizet_str(a, 'a', s);
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
		rez++;
	}
	return (rez);
}

int		print_rezult_pointer(size_t a, int size, t_info *inf)
{
	int rez;

	rez = 0;
	if (size < inf->width && inf->flags == -1)
	{
		rez += print_count_char(inf->width - size, ' ');
		rez += print_pointer(a, inf);
	}
	else if (size < inf->width && inf->flags == 1)
	{
		rez += print_pointer(a, inf);
		rez += print_count_char(inf->width - size, ' ');
	}
	else if (size >= inf->width)
		rez += print_pointer(a, inf);
	return (rez);
}

int		ft_print_pointer(size_t a, t_info *inf)
{
	int size;

	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
	if (inf->flags == 0)
		return (-1);
	if (inf->precision == 0 && a == 0)
		size = 2;
	else
		size = count_pointer(a);
	return (print_rezult_pointer(a, size, inf));
}
