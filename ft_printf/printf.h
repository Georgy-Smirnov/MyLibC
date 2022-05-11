/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:41:02 by kjaco             #+#    #+#             */
/*   Updated: 2021/01/18 19:57:38 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_info
{
	int		flags;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_info;
int				search_number(const char *str, int *i, va_list ap);
int				check_type(char sym);
void			new_inf(t_info *inf);
int				ft_parsing(const char *str, va_list ap, t_info *inf);
int				ft_second_printf(const char *str, va_list ap);
int				ft_printf(const char *str, ...);
int				print_variable(va_list ap, t_info *inf);
int				print_count_char(int i, char c);
int				ft_print_string(char *str, t_info *inf);
int				ft_print_int(int a, t_info *inf);
int				ft_print_number(long long int a, int size);
int				ft_print_symbol(char c, t_info *inf);
int				count_digit_in_number(long long int a);
int				count_dec_hex(unsigned int a);
int				ft_print_unint(unsigned int a, t_info *inf);
int				ft_print_hex(unsigned int a, t_info *inf);
int				ft_print_bighex(unsigned int a, t_info *inf);
int				ft_print_pointer(size_t a, t_info *inf);
int				ft_print_percent(t_info *inf);
char			*put_null(char *str);
int				ft_print_exep(t_info *inf);
int				put_sizet_str(size_t a, char c, char *s);

int				ft_strlen(char *str);
int				ft_atoi(const char *str);
void			ft_putnbr_fd(long long int n, int fd);
void			ft_putchar_fd(char c, int fd);

#endif
