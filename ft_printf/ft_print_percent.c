/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:26:16 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 20:53:43 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_width(t_info *inf)
{
	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
}

int		ft_print_percent(t_info *inf)
{
	int rez;

	rez = 0;
	check_width(inf);
	if (inf->width > 1 && inf->flags == -1)
	{
		rez += print_count_char(inf->width - 1, ' ') + 1;
		write(1, "%", 1);
	}
	else if (inf->width > 1 && inf->flags == 0)
	{
		rez += print_count_char(inf->width - 1, '0') + 1;
		write(1, "%", 1);
	}
	else if (inf->width > 1 && inf->flags == 1)
	{
		write(1, "%", 1);
		rez += print_count_char(inf->width - 1, ' ') + 1;
	}
	else if (inf->width <= 1 && ++rez)
		write(1, "%", 1);
	return (rez);
}

int		ft_print_exep(t_info *inf)
{
	int rez;

	rez = 0;
	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
	if (inf->width > 0 && inf->flags == -1)
	{
		rez += print_count_char(inf->width, ' ');
	}
	else if (inf->width > 0 && inf->flags == 0)
	{
		rez += print_count_char(inf->width, ' ');
	}
	else if (inf->width > 0 && inf->flags == 1)
	{
		rez += print_count_char(inf->width, ' ');
	}
	return (rez);
}
