/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:55:49 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 20:33:42 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		search_flag(const char *str, t_info *inf)
{
	int i;
	int z;

	i = 1;
	z = -1;
	new_inf(inf);
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			z = 1;
		if (str[i] == '0' && z != 1)
			z = 0;
		i++;
	}
	inf->flags = z;
	return (i);
}

int		ft_parsing(const char *str, va_list ap, t_info *inf)
{
	int i;

	i = search_flag(str, inf);
	inf->width = search_number(str, &i, ap);
	if (str[i] == '.')
	{
		i++;
		inf->precision = search_number(str, &i, ap);
	}
	if (inf->precision < -1)
		inf->precision = -1;
	if (check_type(str[i]))
		inf->type = str[i];
	else
		return (-1);
	if ((inf->length += print_variable(ap, inf)) == -1)
		return (-1);
	i++;
	return (i);
}

void	new_inf(t_info *inf)
{
	inf->flags = 0;
	inf->width = 0;
	inf->precision = -1;
	inf->type = ' ';
}

int		print_variable(va_list ap, t_info *inf)
{
	int rez;

	rez = 0;
	if (inf->type == 's')
		rez = ft_print_string(va_arg(ap, char*), inf);
	if (inf->type == 'd' || inf->type == 'i')
		rez = ft_print_int(va_arg(ap, int), inf);
	if (inf->type == 'c')
		rez = ft_print_symbol(va_arg(ap, int), inf);
	if (inf->type == '%')
		rez = ft_print_percent(inf);
	if (inf->type == 'u')
		rez = ft_print_unint(va_arg(ap, unsigned int), inf);
	if (inf->type == 'p')
		rez = ft_print_pointer((size_t)va_arg(ap, void*), inf);
	if (inf->type == 'x')
		rez = ft_print_hex(va_arg(ap, unsigned int), inf);
	if (inf->type == 'X')
		rez = ft_print_bighex(va_arg(ap, unsigned int), inf);
	return (rez);
}
