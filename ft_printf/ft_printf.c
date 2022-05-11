/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:59:20 by kjaco             #+#    #+#             */
/*   Updated: 2021/04/03 14:17:06 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		search_number(const char *str, int *i, va_list ap)
{
	int		rez;
	char	number[15];
	int		j;

	rez = 0;
	j = 0;
	if ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
	{
		if (str[*i] == '*')
		{
			rez = va_arg(ap, int);
			(*i)++;
		}
		else
		{
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				number[j++] = str[*i];
				(*i)++;
			}
			number[j] = 0;
			rez = ft_atoi(number);
		}
	}
	return (rez);
}

int		check_type(char sym)
{
	if (sym == 'c' || sym == 's' || sym == 'p' || sym == 'd')
		return (1);
	if (sym == 'i' || sym == 'u' || sym == 'x' || sym == 'X' || sym == '%')
		return (1);
	return (0);
}

void	print_without_persent(char c, int *i, int *length)
{
	write(1, &c, 1);
	(*i)++;
	(*length)++;
}

int		ft_second_printf(const char *str, va_list ap)
{
	t_info	*inf;
	int		i;
	int		check;

	if ((inf = (t_info *)malloc(17)) == NULL)
		return (-1);
	inf->length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((check = ft_parsing(&str[i], ap, inf)) != -1)
				i += check;
			else
				return (-1);
		}
		else
			print_without_persent(str[i], &i, &inf->length);
	}
	i = inf->length;
	free(inf);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = ft_second_printf(str, ap);
	va_end(ap);
	return (count);
}
