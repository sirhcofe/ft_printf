/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:15:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 22:22:31 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_number(const char *format, t_flags *flag, int *i)
{
	int	j;

	j = 0;
	while (ft_isdigit(format[*i + j]))
		j++;
	if (flag->precisn == 0)
		flag->nmbr_bfore_prcn = ft_substr(format + *i, 0, j);
	else
		flag->nmbr_after_prcn = ft_substr(format + *i, 0, j);
	// if (flag->precisn == 0)
	// 	flag->nmbr_bfore_prcn = ft_strjoin(flag->nmbr_bfore_prcn, &format[*i]);
	// else
	// 	flag->nmbr_after_prcn = ft_strjoin(flag->nmbr_after_prcn, &format[*i]);
}

#include <stdio.h>
void	identify_spec(const char *format, t_flags *flag)
{
	int		i;

	i = -1;
	while (++i <= flag->count)
	{
		if (format[i] == '-')
			flag->minus += 1;
		else if (format[i] == '+')
			flag->plus += 1;
		else if (format[i] == ' ')
			flag->blank += 1;
		else if (format[i] == '0')
			flag->zero += 1;
		else if (format[i] == '#')
			flag->hash += 1;
		else if (format[i] == '.')
			flag->precisn += 1;
		else if (ft_isdigit(format[i]))
			parse_number(format, flag, &i);
		else if (ft_strchr(CHARACTER, format[i]))
			flag->chars = format[i];
	}
	flag->flag_str = ft_substr(format, 0, (flag->count + 1));
	printf("nmbr_bfore_prcn = %s\n", flag->nmbr_bfore_prcn);
}

void	initiate_reset_tflags(t_flags *flag)
{
	// if (flag->flag_str)
	// 	free(flag->flag_str);
	// if (flag->nmbr_bfore_prcn)
	// 	free(flag->nmbr_bfore_prcn);
	// if (flag->nmbr_after_prcn)
	// 	free(flag->nmbr_after_prcn);
	flag->flag_str = NULL;
	flag->nmbr_bfore_prcn = NULL;
	flag->nmbr_after_prcn = NULL;
	flag->count = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->precisn = 0;
	flag->hash = 0;
	flag->chars = 0;
}

void	parse_format(const char *format, va_list args, t_len *len)
{
	t_flags	*flag;
	int		i;

	i = -1;
	flag = malloc(sizeof(t_flags));
	while (format[++i])
	{
		if (format[i] == '%' && (format[i + 1]) != '\0')
		{
			initiate_reset_tflags(flag);
			while (ft_strchr(ALL, format[++i]))
			{
				flag->count += 1;
				if (ft_strchr(CHARACTER, format[i]))
					break;
			}
			identify_spec((format + i + 1 - flag->count), flag);
			if (flag->chars != 0)
				print_flag_specifier(args, flag, len);
		}
		else
			len->n += write(1, &format[i], 1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_len		*len;

	len = malloc(sizeof(t_len));
	len->n = 0;
	va_start(args, format);
	parse_format(format, args, len);
	va_end(args);
	return (len->n);
}
