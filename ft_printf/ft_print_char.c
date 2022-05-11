/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:52:57 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/17 14:26:37 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_symbol(char c, t_info *inf)
{
	int rez;

	rez = 0;
	if (inf->width < 0)
	{
		inf->flags = 1;
		inf->width = -inf->width;
	}
	if (inf->precision != -1)
		return (-1);
	if (inf->width > 1 && inf->flags == -1)
	{
		rez += print_count_char(inf->width - 1, ' ') + 1;
		write(1, &c, 1);
	}
	else if (inf->width > 1 && inf->flags == 1)
	{
		write(1, &c, 1);
		rez += print_count_char(inf->width - 1, ' ') + 1;
	}
	else if (inf->width <= 1 && ++rez)
		write(1, &c, 1);
	return (rez);
}
