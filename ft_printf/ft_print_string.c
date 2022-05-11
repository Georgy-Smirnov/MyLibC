/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:01:54 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 19:31:48 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putstr(char *str, int i)
{
	int rez;

	rez = 0;
	while (i)
	{
		write(1, str, 1);
		i--;
		rez++;
		str++;
	}
	return (rez);
}

int		print_count_char(int i, char c)
{
	int rez;

	rez = 0;
	while (i)
	{
		write(1, &c, 1);
		i--;
		rez++;
	}
	return (rez);
}

int		print_rezult_str(char *str, int size, int width, int flags)
{
	int rez;

	rez = 0;
	if (size < width && flags == -1)
	{
		rez += print_count_char(width - size, ' ');
		rez += ft_putstr(str, size);
	}
	else if (size < width && flags == 1)
	{
		rez += ft_putstr(str, size);
		rez += print_count_char(width - size, ' ');
	}
	else if (size >= width)
		rez += ft_putstr(str, size);
	return (rez);
}

int		ft_print_string(char *str, t_info *inf)
{
	int size;

	if (str == NULL)
		str = "(null)";
	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
	if (ft_strlen(str) > inf->precision && inf->precision != -1)
		size = inf->precision;
	else
		size = ft_strlen(str);
	return (print_rezult_str(str, size, inf->width, inf->flags));
}
